//       """ Talk is cheap ; show me the code!!! """
 
//                -Linus Torvalds     

//// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+==+=+==+=+=
//                                        MAIN_HEADER
//// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+==+=+==+=+=

#pragma once

#ifndef configuration
#define configuration

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <dirent.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>

//#include <regex.h>

// with -lcurl lib option while you compiling.
// i.e. gcc requests.c -lcurl
//#include <curl/curl.h>


#define SIZE 101
#define BUFFER_SIZE 1024

//for modes
#define char_mode 1
#define str_mode 2
#define file_mode 3

//for settings
#define file_set 1
#define manual_set 2

//for file
//FILE *fpt;


// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                                Global Variable
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
// will be decalared as false when the machine turns off and vise versa.
// @notice: it allows us to use pauseable design pattern too.
// NOTE: don't change this variable directly. just via its function:`change_mode`.
// #ifndef machine_mode 
extern bool machine_mode;
// #endif

// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                                Rotor_Data_Type
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
// @title:  Rotor data type decleration... 
// @author: Mohammad Siamaki
// @notice: This struct can be modified later... .
// @dev   : every Rotor has a starting position called "position",
//          an indicator for shifting called "ShiftChar",
//          and values on the out put i.e "ArrRotor"... .
// @custom : we assume that the reflector is a constant rotor so we have 4 rotors
// @note A simulation for rotors of machine
// @dev A replacement for a struct could be more efficient
/*
struct Rotor
{
    int Position;
    int ShiftChar;
    char ArrRotor[26];//Every rotor has a set of 26 possible outputs i.e. "A-->z"
};
typedef struct Rotor Rotor;//unpro naming but anyway we call our instances "Rotor" 
*/
typedef struct
{
    int Position;
    int ShiftChar;
    char ArrRotor[26];//Every rotor has a set of 26 possible outputs i.e. "A-->z"
} Rotor;



// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                       PLUG_IN_PORTS
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
// @title:  PLUG_IN_PORTS... 
// @author: Mohammad Siamaki
// @notice: This array is connected to the .log files and config ones... .
// @dev   : The elements on the array show the output of the reflector
//          e.g. "N" replaces "A".we will not measure the copper wires;instead
//          we consider the output of the reflector on a certain out going port.

//@custom : side note: In programming the reflector can return itself but
//          in physical world we cant do so,meaning we can take this simu 
//          much further...


// moved to  "config.c"
// extern char ArrPlug[26];



// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                 Function_Prototypes _login.c
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//           i.e. : func declerations used in login.c


//MUST BE CALLED BEFORE EVERYTHING TO ACCESS SIMULATOR
void login();



// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                 Function_Prototypes _verification.c
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//           i.e. : func declerations used in verification.c


bool signin(char *_username, char *_password);
bool signup(char *_username, char *_password);


// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                 Function_Prototypes _mode.c
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//           i.e. : func declerations used in mode.c


//MUST BE CALLED FOR SELECTING MODE
int select_mode();


// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                 Function_Prototypes _log_table.c
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//           i.e. : func declerations used in log_table.c


void indicate_data_generated(char *data);


// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                 Function_Prototypes _Enigma.c
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//           i.e. : func declerations used in enigma.c

// 
int select_settings();

// 
void read_settings(int rotor_number,int *r1n,int *r1p,int *r2n,int *r2p,int *r3n,int *r3p,char *plugs);

// MUST BE CALLED TO INITIALIZE ROTORS
//RETURNS AN ARRAY OF THREE ROTORS
//EXAMPLE: {2,'B',Arrrotor}
void rotorinit(Rotor rotor_array[3], Rotor *default_rotors, int n);

// 
void plugboard_init(char plug_arr[26]);

// 
void add_remove_rotor(Rotor *default_rotors, int *n);

// @param c is a character
// @param arr[] is an array of characters
// @returns The index of a character in the array passed to it (arr[])
int indexof(char c, char arr[]);

// @note The input character goes here after the plugboard
// @param rotor is the rotor instructed to be used in the machine
// @param Input is the output of the previous rotor or plugboard
// @param InputChar specifies wethear the rotor needs to shift or not
// @param check tells the function wethear to print the output or not
// @returns The ASCII number of the rotors output character minus rotor's position
int pre_reflector(Rotor *rotor, int Input, int InputChar);

// @note After passing the reflector, it is time to go back through the rotors
// @dev Is there anyway to call the rotors more efficiently?
// @param rotor is the rotor instructed to be used in the machine
// @param Input is the output of the previous rotor or reflector
// @returns The ASCII number of the rotors output character, minus rotor's position
int post_reflector(Rotor *rotor, int input);

// @note First, user's input goes to this function to get checked in the ArrPlug array
// @param c is the user-input character
// @param arr[] is the ArrPlug assinged previously
// @returns The ASCII number of character which was 'connected' to the input character in plugboard
char plugboard(char c, char arr[]);

// This function is used to configure the Rotors and the plugboard, to encode or decode a letter...
void config(Rotor RotorsArr[4], char plugboard[26]);

// @notice: Use this function during the Enigma algorithm workflow when you reach to the 
//   last section of encryption. (for log/config handling).
//     It will change the global `is_last_operation` variable in did.
void change_mode(char *last_input, char *last_output);

// 
void enigma(int selected_mode, Rotor RotorsArr[4], char ArrPlug[26]);



// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                          MORSE_CODE_HEADER
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
// IMPORTANT NOTE : USEFUL INFORMATION IS IN "MorseCode.c"

extern const char* CHAR_TO_MORSE[128];//defined in config.c
extern const char* MORSE_TO_CHAR[128];//defined in config.c

// In the config.c we have :

// These dot and line combo's are morse code configuration
// const char* CHAR_TO_MORSE[128] = {
//        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
//        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
//        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
//        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
//        NULL, "-.-.--", ".-..-.", NULL, NULL, NULL, NULL, ".----.",
//        "-.--.", "-.--.-", NULL, NULL, "--..--", "-....-", ".-.-.-", "-..-.",
//        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
//        "---..", "----.", "---...", NULL, NULL, "-...-", NULL, "..--..",
//        ".--.-.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
//        "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
//        ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
//        "-..-", "-.--", "--..", NULL, NULL, NULL, NULL, "..--.-",
//        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
//        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
//        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
//        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
//};

//const char* MORSE_TO_CHAR[128] = {
//        NULL, NULL, "E", "T", "I", "N", "A", "M",
//        "S", "D", "R", "G", "U", "K", "W", "O",
//        "H", "B", "L", "Z", "F", "C", "P", NULL,
//        "V", "X", NULL, "Q", NULL, "Y", "J", NULL,
//        "5", "6", NULL, "7", NULL, NULL, NULL, "8",
//        NULL, "/", NULL, NULL, NULL, "(", NULL, "9",
//        "4", "=", NULL, NULL, NULL, NULL, NULL, NULL,
//        "3", NULL, NULL, NULL, "2", NULL, "1", "0",
//        NULL, NULL, NULL, NULL, NULL, NULL, NULL, ":",
//        NULL, NULL, NULL, NULL, "?", NULL, NULL, NULL,
//        NULL, NULL, "\"", NULL, NULL, NULL, "@", NULL,
//        NULL, NULL, NULL, NULL, NULL, NULL, "'", NULL,
//        NULL, "-", NULL, NULL, NULL, NULL, NULL, NULL,
//        NULL, NULL, ".", NULL, "_", ")", NULL, NULL,
//        NULL, NULL, NULL, ",", NULL, "!", NULL, NULL,
//        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
//};



//-----------------------------------
//func_prototypes used in MorseCode.c
//-----------------------------------
const char* char_to_morse(char);
const char* morse_to_char(const char*);
int morse_to_index(const char*);

//--------------------------------------





// // +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
// //                          LOGGING_CODE_HEADER
// // +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                        //DECLARATIONS MADE BY P.AMINPOUR

// // 
void logging(char *input, char *output, char *stage);


//these moved to the "logging.c" file
// enum Level {
//     INFO, // 0
//     WARNING, // 1                               
//     ERROR //2
// };

// enum Level level_number(int _lvl) {
//     return _lvl;
// };

// struct LogStruct {
//     char _date[SIZE];
//     char _time[SIZE];
//     char _file_name[SIZE];
//     char _stage[SIZE];
//     char _input[SIZE];
//     char _output[SIZE];
//     enum Level _level;
// };

#endif//Enjoy the comment system
//thanks Solidity :D  


//End of file... .