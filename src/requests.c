#include "config.h"

int request(char *url)
{
	// Stores the CURL handle used to manage the request and easy API session
  	CURL *curl;

  	// Stores the return value of the call to curl_easy_perform()
  	CURLcode result;
  
  	// Starts the session, return the curl handle we'll use to setup the request
  	curl = curl_easy_init();

  	if (curl == NULL)
  	{
    	fprintf(stderr, "HTTP request failed\n");
    	return -1;
  	}

  	curl_easy_setopt(curl, CURLOPT_URL, url);
  
  	// result will store in a string.
  	// If the request is OK we'll get back CURLE_OK as a return value
  	result = curl_easy_perform(curl);
  
  	if (result != CURLE_OK)
  	{
    	fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
    	return -1;
 	}
       
	// We call curl_easy_cleanup() to complete/close the session, just like websockets.
	curl_easy_cleanup(curl);
 
	return 0;
}


int _url_verification(char *_url) {
	regex_t reegex;

	int compare_result;

	char re_pattern[SIZE] = "(https:\/\/www\.|http:\/\/www\.|https:\/\/|http:\/\/)?[a-zA-Z0-9]{2,}(\.[a-zA-Z0-9]{2,})(\.[a-zA-Z0-9]{2,})?";
	compare_result = regcomp(&reegex, re_pattern, 0);

	return compare_result;
}


int main() {
	char *url = (char*) malloc(SIZE * sizeof(char));
	return 0;
}