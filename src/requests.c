#include "config.h"

// I had to got this Regex pattern from the StackOverflow. We could have a better Regex pattern.
const char *re_pattern = "^(https?|ftp)://[-a-zA-Z0-9+&@#/%?=~_|!:,.;]*[-a-zA-Z0-9+&@#/%=~_|]";

const char* _getRegexError(int code) {
 	switch(code) {
    	case REG_NOMATCH: return "No match";
    	case REG_ECOLLATE: return "Invalid collating element";
    	case REG_ECTYPE: return "Invalid character class";
    	case REG_EESCAPE: return "Trailing backslash";
  	}
  	return "Unknown regex error";
}


bool _validate_url(const char *_url, const char *_re_pattern) {
  	regex_t regex;
  	int result;

  	result = regcomp(&regex, _re_pattern, REG_EXTENDED);

  	if (result != 0) {
    	fprintf(stderr, "%s\n", _getRegexError(result));
    	return false;
 	}

  	result = regexec(&regex, _url, 0, NULL, 0);
  	regfree(&regex);
  
  	return result == 0; 
}


void request(char *_url)
{
	bool validate_url = _validate_url(_url, re_pattern);
	if (!validate_url) exit(-1);

	// Stores the CURL handle used to manage the request and easy API session
  	CURL *curl;

  	// Stores the return value of the call to curl_easy_perform()
  	CURLcode result;
  
  	// Starts the session, return the curl handle we'll use to setup the request
  	curl = curl_easy_init();

  	if (curl == NULL)
  	{ 
    	fprintf(stderr, "HTTP request failed\n");
    	exit(-1);
  	}

  	curl_easy_setopt(curl, CURLOPT_URL, _url);
  
  	// result will store in a string.
  	// If the request is OK we'll get back CURLE_OK as a return value
  	result = curl_easy_perform(curl);
  
  	if (result != CURLE_OK)
  	{
    	fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));	
    	exit(-1);
 	}
    
    // printf("%s\n", result);
	// We call curl_easy_cleanup() to complete/close the session, just like websockets.
	curl_easy_cleanup(curl);
 
	return;
}


// NOTE: This is just a sample of the requests.c workflow and should be deleted in the production phase.
int main() {
	char *url = (char*) malloc(SIZE * sizeof(char));
	scanf("%s", url);
	request("https://www.google.com");
}