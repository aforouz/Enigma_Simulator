
//// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+==+=+==+=+=
//                                        MAIN_HEADER
//// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+==+=+==+=+=

#ifndef CONFIG
#define CONFIG

#include "Header.h"

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