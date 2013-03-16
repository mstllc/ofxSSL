meta:
	ADDON_NAME = ofxSSL
	ADDON_DESCRIPTION = CURL Addon
	ADDON_AUTHOR = @thorsonmscott @bakercp @timscaffidi 
	ADDON_TAGS = "network" "web"
	ADDON_URL = https://github.com/thorsonmscott/ofxSSL

common:

linux64:
	# linux only, any library that should be included in the project using
	# pkg-config
	ADDON_PKG_CONFIG_LIBRARIES = libcurl

	# this forces us to use pkg-config headers in the addon
	ADDON_INCLUDES_EXCLUDE = libs
	ADDON_INCLUDES_EXCLUDE += libs/%
	
linux:
	# linux only, any library that should be included in the project using
	# pkg-config
	ADDON_PKG_CONFIG_LIBRARIES = libcurl
	
	# this forces us to use pkg-config headers in the addon
	ADDON_INCLUDES_EXCLUDE = libs
	ADDON_INCLUDES_EXCLUDE += libs/%

win_cb:
	# linux only, any library that should be included in the project using
	# pkg-config
	ADDON_PKG_CONFIG_LIBRARIES = libcurl
	
	# this forces us to use pkg-config headers in the addon
	ADDON_INCLUDES_EXCLUDE = libs
	ADDON_INCLUDES_EXCLUDE += libs/%

linuxarmv6l:
	# linux only, any library that should be included in the project using
	# pkg-config
	ADDON_PKG_CONFIG_LIBRARIES = libcurl
	
	# this forces us to use pkg-config headers in the addon
	ADDON_INCLUDES_EXCLUDE = libs
	ADDON_INCLUDES_EXCLUDE += libs/%
linuxarmv7l:
	# linux only, any library that should be included in the project using
	# pkg-config
	ADDON_PKG_CONFIG_LIBRARIES = libcurl

	# this forces us to use pkg-config headers in the addon
	ADDON_INCLUDES_EXCLUDE = libs
	ADDON_INCLUDES_EXCLUDE += libs/%

android/armeabi:	
	
android/armeabi-v7a:
