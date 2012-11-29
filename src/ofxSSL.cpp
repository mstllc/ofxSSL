//
//  ofxSSL.cpp
//  sslTest
//
//  Created by Thorson, Max on 1/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ofxSSL.h"
#include <string>


//--------------------------------------------------------------
ofxSSL::ofxSSL() {
//    ofAddListener(ofEvents().setup, this, &ofxSSL::setup);
}

//--------------------------------------------------------------
ofxSSL::~ofxSSL() {
    cleanup();
//	ofRemoveListener(ofEvents().setup, this, &ofxSSL::setup);
}

//--------------------------------------------------------------
void ofxSSL::setup(ofEventArgs &e) {
    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    post = NULL;
    last = NULL;
    header_list = NULL;
    uploadFile = NULL;
    curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 0);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, true);
    curl_easy_setopt(handle, CURLOPT_VERBOSE, true);
    curl_easy_setopt(handle, CURLOPT_CAINFO, ofToDataPath("cacert.pem").c_str());
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, content_writer);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &content);
    curl_easy_setopt(handle, CURLOPT_HEADERFUNCTION, header_writer);
    curl_easy_setopt(handle, CURLOPT_HEADERDATA, &header);
}

void ofxSSL::setup(){
    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    post = NULL;
    last = NULL;
    header_list = NULL;
    uploadFile = NULL;
    curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 0);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, true);
    curl_easy_setopt(handle, CURLOPT_VERBOSE, true);
    curl_easy_setopt(handle, CURLOPT_CAINFO, ofToDataPath("cacert.pem").c_str());
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, content_writer);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &content);
    curl_easy_setopt(handle, CURLOPT_HEADERFUNCTION, header_writer);
    curl_easy_setopt(handle, CURLOPT_WRITEHEADER, &header);
}

//--------------------------------------------------------------
void ofxSSL::setURL(const string& url) {
    curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
}

//--------------------------------------------------------------
void ofxSSL::setOpt(CURLoption option, const string& value) {
    
    curl_easy_setopt(handle, option, value.c_str());
}

//--------------------------------------------------------------
void ofxSSL::setOpt(CURLoption option, int value) {
    
    curl_easy_setopt(handle, option, value);
}

void ofxSSL::setUploadFile(string filename) {
    
    uploadFile = fopen(ofFilePath::getAbsolutePath(filename).c_str(), "rb");
    curl_easy_setopt(handle, CURLOPT_UPLOAD, 1);
    curl_easy_setopt(handle, CURLOPT_READDATA, uploadFile);

}

//--------------------------------------------------------------
void ofxSSL::addFormField(const string& fieldName, const string& value) {
    
    curl_formadd(&post, &last, CURLFORM_COPYNAME, fieldName.c_str(), CURLFORM_COPYCONTENTS, value.c_str(), CURLFORM_END);    
}

//--------------------------------------------------------------
void ofxSSL::addFormField(CURLformoption optionA, const string& valueA, CURLformoption optionB, const string& valueB) {
    
    curl_formadd(&post, &last, optionA, valueA.c_str(), optionB, valueB.c_str());
}

void ofxSSL::addHeader(string header_line){
    
    header_list = curl_slist_append(header_list, header_line.c_str());
}

//--------------------------------------------------------------
void ofxSSL::perform() {
    
    if(post != NULL) curl_easy_setopt(handle, CURLOPT_HTTPPOST, post);
    if(header_list != NULL) curl_easy_setopt(handle, CURLOPT_HTTPHEADER, header_list);
    
    ret = curl_easy_perform(handle);
    if(CURLE_OK != ret) {
        ofLogError("ofxSSL") << curl_easy_strerror(ret);
    }
    
    if(post != NULL) {
        curl_formfree(post);
        post = NULL;
    }
    if (header_list != NULL) {
        curl_slist_free_all(header_list);
        header_list = NULL;
    }
    if(uploadFile != NULL) {
        fclose(uploadFile);
        uploadFile = NULL;
    }
}

//--------------------------------------------------------------
void ofxSSL::cleanup() {
    
    if(handle != NULL) {
        curl_easy_cleanup(handle);
        handle = NULL;
    }
    if(post != NULL) {
        curl_formfree(post);
        post = NULL;
    }
    if (header_list != NULL) {
        curl_slist_free_all(header_list);
        header_list = NULL;
    }
    if(uploadFile != NULL) {
        fclose(uploadFile);
        uploadFile = NULL;
    }
    content = "";
    header = "";
}

//--------------------------------------------------------------
string ofxSSL::getResponseHeader() const {
    return header;
}

//--------------------------------------------------------------
string ofxSSL::getResponseBody() const {
    return content;
}

//--------------------------------------------------------------
size_t ofxSSL::content_writer(char *ptr, size_t size, size_t nmemb, string userdata) {
        
    string content(static_cast<const char*>(ptr), size * nmemb);
    userdata = content;
        
    return size * nmemb;
}

//--------------------------------------------------------------
size_t ofxSSL::header_writer(char *ptr, size_t size, size_t nmemb, string userdata) {
    
    string header(static_cast<const char*>(ptr), size * nmemb);
    userdata += header;
    
    return size * nmemb;
}