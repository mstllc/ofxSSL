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
    
    //methods
    void init();
    void setURL(string url);
    void setOpt(CURLoption option, string value);
    void setOpt(CURLoption option, int value);
    void addFormField(string fieldName, string value);
    void addFormField(CURLformoption optionA, string valueA, CURLformoption optionB, string valueB);
    void perform();
    void cleanup();
    
    string getString();
    
    //variables
    CURL* handle;

    
private:
    
    //methods
    static size_t writer(char *ptr, size_t size, size_t nmemb, string userdata);
    
    //variables
    struct curl_httppost *post;
    struct curl_httppost *last;
    CURLcode ret;
    string content;
    
};

