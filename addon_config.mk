meta:
	ADDON_NAME = ofxSSL
	ADDON_DESCRIPTION = CURL Addon
	ADDON_AUTHOR = @thorsonmscott @bakercp @timscaffidi 
	ADDON_TAGS = "network" "web"
	ADDON_URL = https://github.com/thorsonmscott/ofxSSL

common:
linux64:
	ADDON_INCLUDES_EXCLUDE = libs
	ADDON_INCLUDES_EXCLUDE += libs%
	ADDON_PKG_CONFIG_LIBRARIES = libcurl
linux:
        ADDON_INCLUDES_EXCLUDE = libs
        ADDON_INCLUDES_EXCLUDE += libs%
        ADDON_PKG_CONFIG_LIBRARIES = libcurl
linuxarmv6l:
        ADDON_INCLUDES_EXCLUDE = libs
        ADDON_INCLUDES_EXCLUDE += libs%
        ADDON_PKG_CONFIG_LIBRARIES = libcurl
linuxarmv7l:
        ADDON_INCLUDES_EXCLUDE = libs
        ADDON_INCLUDES_EXCLUDE += libs%
        ADDON_PKG_CONFIG_LIBRARIES = libcurl
android/armeabi:	
android/armeabi-v7a:
