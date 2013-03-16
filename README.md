ofxSSL
======

openFrameworks addon wrapping libcURL with support for SSL requests using openSSL.

Tested and up to date with 0.7.4+

openSSL libraries are now included with openFrameworks by default.

Curl binaries for OSX are included in this package.

For linux, make sure you have the following package installed:

`apt-get install libcurl4-openssl-dev`

BasicExample project makes three curl requests, the third of which is over SSL.  Watch the console for curl reporting.

