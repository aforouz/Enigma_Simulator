#include "config.h"

// This is a test for Morsecode.c
// Author : A.Jafari
// Notice that function prototypes are provided in the headers.


// chtom = char to morse
void test_chtom()
{
    // check an example of the function and it declares whether the test is successful or not.
    const char* result = char_to_morse('A');
    if (strcmp(result, ".-") != 0)
    {
        printf("Char to Morse: Failed!\n");
    }
    else
    {
        printf("Char to Morse: Passed!\n");
    }

}

// mtoch = morse to char
void test_mtoch()
{
    // check an example of the function and it declares whether the test is successful or not.
    const char* result = morse_to_char(".-");
    if (strcmp(result, "A") != 0)
    {
        printf("Morse to Char: Failed!\n");
    }
    else
    {
        printf("Morse to Char: Passed!\n");
    }
}

int main()
{
    // Here the functions are called to see the test result.
    test_chtom();
    test_mtoch();
    return 0;
}