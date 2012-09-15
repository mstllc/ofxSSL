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
    ofAddListener(ofEvents().setup, this, &ofxSSL::setup);
}

//--------------------------------------------------------------
ofxSSL::~ofxSSL() {
    cleanup();
	ofRemoveListener(ofEvents().setup, this, &ofxSSL::setup);
}

//--------------------------------------------------------------
void ofxSSL::setup(ofEventArgs &e) {
    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    post = NULL;
    last = NULL;
    curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 0);
    curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, true);
    curl_easy_setopt(handle, CURLOPT_VERBOSE, true);
    curl_easy_setopt(handle, CURLOPT_CAINFO, ofToDataPath("cacert.pem").c_str());
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &content);
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

//--------------------------------------------------------------
void ofxSSL::addFormField(const string& fieldName, const string& value) {
    
    curl_formadd(&post, &last, CURLFORM_COPYNAME, fieldName.c_str(), CURLFORM_COPYCONTENTS, value.c_str(), CURLFORM_END);    
}

//--------------------------------------------------------------
void ofxSSL::addFormField(CURLformoption optionA, const string& valueA, CURLformoption optionB, const string& valueB) {
    
    curl_formadd(&post, &last, optionA, valueA.c_str(), optionB, valueB.c_str());
}

//--------------------------------------------------------------
void ofxSSL::perform() {
    
    if(post != NULL) curl_easy_setopt(handle, CURLOPT_HTTPPOST, post);
    
    ret = curl_easy_perform(handle);
    if(CURLE_OK != ret) {
        ofLogError("ofxSSL") << curl_easy_strerror(ret);
    }
    
    if(post != NULL) curl_formfree(post);    
}

//--------------------------------------------------------------
void ofxSSL::cleanup() {
    curl_easy_cleanup(handle);
    if(post != NULL) curl_formfree(post); 
}

//--------------------------------------------------------------
string ofxSSL::getString() const {
    return content;
}

//--------------------------------------------------------------
size_t ofxSSL::writer(char *ptr, size_t size, size_t nmemb, string userdata) {
        
    string content(static_cast<const char*>(ptr), size * nmemb);
    userdata = content;
        
    return size * nmemb;
}