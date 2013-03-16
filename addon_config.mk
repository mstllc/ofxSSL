meta:
	ADDON_NAME = ofxSSL
	ADDON_DESCRIPTION = CURL Addon
	ADDON_AUTHOR = @thorsonmscott @bakercp @timscaffidi 
	ADDON_TAGS = "network" "web"
	ADDON_URL = https://github.com/thorsonmscott/ofxSSL

common:
	# linux only, any library that should be included in the project using
	# pkg-config
	ADDON_PKG_CONFIG_LIBRARIES = libcurl