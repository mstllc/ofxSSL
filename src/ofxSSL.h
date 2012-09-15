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
    void setURL(const string& url);
    void setOpt(CURLoption option, const string& value);
    void setOpt(CURLoption option, int value);
    void addFormField(const string& fieldName, const string& value);
    void addFormField(CURLformoption optionA, const string& valueA, CURLformoption optionB, const string& valueB);
    void perform();
    
    string getString() const;

protected:
    //variables
    CURL* handle;

    void cleanup();
    
private:
    
    //methods
    static size_t writer(char *ptr, size_t size, size_t nmemb, string userdata);
    
    //variables
    struct curl_httppost *post;
    struct curl_httppost *last;
    CURLcode ret;
    string content;
    
};

