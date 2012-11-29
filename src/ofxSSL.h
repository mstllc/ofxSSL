//
//  ofxSSL.h
//  sslTest
//
//  Created by Thorson, Max on 1/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "curl.h"
#include <string>

class ofxSSL {
public:
    
    //constructor
    ofxSSL();
    virtual ~ofxSSL();
    
    //methods
    void setup(ofEventArgs &e);
    void setup();
    void setURL(const string& url);
    void setOpt(CURLoption option, const string& value);
    void setOpt(CURLoption option, int value);
    void setUploadFile(string filename);
    void addFormField(const string& fieldName, const string& value);
    void addFormField(CURLformoption optionA, const string& valueA, CURLformoption optionB, const string& valueB);
    void addHeader(string header_line);
    void perform();
    
    string getResponseHeader() const;
    string getResponseBody() const;

    void cleanup();
protected:
    //variables
    CURL* handle;

    
private:
    
    //methods
    static size_t content_writer(char *ptr, size_t size, size_t nmemb, string userdata);
    static size_t header_writer(char *ptr, size_t size, size_t nmemb, string userdata);
    
    //variables
    struct curl_httppost *post;
    struct curl_httppost *last;
    struct curl_slist *header_list;
    CURLcode ret;
    string content;
    string header;
    FILE * uploadFile;
};

