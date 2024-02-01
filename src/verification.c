#include "enigma_in_func.c"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DATA_SIZE 101
#define MAX_LEN 1024


// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                       Internal Functions
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

/*
/* NOTE: This function is an internal function and it is NOT useable in other files!
/* @dev use this to encrypt given username and password using Enigma Algorithm
/* @param _username you favor username
/* @param _password your favor password which should be checked the security requirement before calling this function.
/* @returns after mixing the username and password, it will returns encrypted value of this mixed data using Enigm Algorithm.
*/
char* _encrypting(char *_username, char *_password) {
	char username[DATA_SIZE], password[DATA_SIZE];
	strcpy(username, _username);
	strcpy(password, _password);

	char *mixed = strcat(username, password);

	// encrypting username and password using Enigma algorithm
	char *encrypted = (char*) malloc(strlen(mixed) * sizeof(char));

	encrypted = enigma_in_func(mixed, strlen(mixed));
	strcat(encrypted, "\n");

	printf(" encrypted -> %s\n", encrypted);

	return encrypted;
}


/*
/* NOTE: This function is an internal function and it is NOT useable in other files!
/* @dev This function will use in the signin function to validate each line of db.txt encrypted file to validate the signin data.
/* @param _password_hashed is encrypted data that contains user data to login.
/* @param _hashed is that hash value inside the db.txt file.
/* @returns true if the _password_hashed and _hashed value were similar.
*/
static bool _check_hash(char *_password_hashed, char *_hashed) {
	if (strlen(_password_hashed) != strlen(_hashed)) return false;

	if (strcmp(_password_hashed, _hashed) != 0) return false;

	return true;
}


/*
/* NOTE: This function is an internal function and it is NOT useable in other files!
/* @dev this function will check the password strength to avoid having unpleasant password.
/* @param _password is the password to evaluate
/* returns true if the password had the requirements, to fullfiled this function the password should contains:
   	--- lowercase, uppercase, digits, special_symbols ---
*/
// check that a password has all requirements, I didn't use regex to reduce complexity.
static bool _check_password_strength(const char *_password) {
    const char *p = _password;
    char c;
    int upper_count = 0;
    int lower_count = 0;
    int digits_count = 0;
    int marks_count = 0;

    // evaluating the password
    while (*p) {
        c = *p++;
        if (isupper(c)) ++upper_count;
        else if (islower(c)) ++lower_count;
        else if (isdigit(c)) ++digits_count;
        else if (ispunct(c)) ++marks_count;
        else continue; // space character
   }

   return upper_count && lower_count && digits_count && marks_count;
}



/*
/* NOTE: This function is an internal function and it is NOT useable in other files!
/* @dev This function will use in singup function to prevent duplicate users.
/* @param _data_encrypted is the encrypted username-password via `_encrypting` function.
/* @returns true if user has been registered before and vise versa.
*/
static bool _user_has_already_registered(char *_data_encrypted) {
	FILE *fp;
	fp = fopen("./machine_files/db.txt", "r");

	char data[MAX_LEN];

	while(!feof(fp) && !ferror(fp)) {
		fgets(data, MAX_LEN, fp);

		if (_check_hash(_data_encrypted, data)) {
			fclose(fp);
			return true;
		}
	}
	fclose(fp);
}





// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                       Useable Functions
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

/*
/* NOTE: Use this function in you project to benefit from verification functionality.
/* @dev Use signup function in the menu/IO user inteface section to have a accsee control system in the Enigma Machine.
/* @param _username is the new username that user gives us.
/* @param _password is the new password that user gives us (which will be evaluated via `_check_password_strength` function).
/* @returns noting and will just append encrypted mixed username-password in `/encrypted_data/db.txt` file.
*/
bool signup(char *_username, char *_password) {
	if(!_check_password_strength(_password)) {
		printf("\n\x1b[31mThe password is too week!\n\x1b[0m");
		return 0;
	}

	char *encrypted = _encrypting(_username, _password);

	if(_user_has_already_registered(encrypted)) {
		printf("\n\x1b[31mThis user information have been registered before!\n\x1b[0m");
		return 0;
	}

	// store this encrypted data to a cloud database or an internal DB
	FILE *data_store;
	
	data_store = fopen("./machine_files/db.txt", "a");

	if (data_store == NULL) {
		printf("\n\x1b[41m The file doesn't exists in the encrypted_data folder!\n\x1b[0m");
		return 0;
	} else fputs(encrypted, data_store);

	fclose(data_store);

	return 1;
}


/*
/* NOTE: Use this function in you project to benefit from verification functionality.
/* @dev Use signin function in the menu/IO user inteface section to have a accsee control system in the Enigma Machine.
/* @param _username is the new username that user gives us.
/* @param _password is the new password that user gives us.
/* @returns true if the verification check fullfiled and user was known as a member of the Enigma Machine's users.
/* NOTE: print the Error message in your own program.
*/
bool signin(char *_username, char *_password) {
	// mixing the username and password.
	FILE *fp;
	fp = fopen("./machine_files/db.txt", "r");

	char *encrypted = _encrypting(_username, _password);

	char data[MAX_LEN];
	while(!feof(fp) && !ferror(fp)) {
		fgets(data, MAX_LEN, fp);

		if (_check_hash(encrypted, data)) {
			fclose(fp);
			return true;
		}
	}
	fclose(fp);

	return false;
}