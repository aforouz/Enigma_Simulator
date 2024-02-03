#ifndef MAIN
#define MAIN

#include "Config.h"

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
//                 Function_Prototypes _finish.c
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//           i.e. : func declerations used in finish.c


void finish();



// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                 Function_Prototypes _last_log.c
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//           i.e. : func declerations used in last_log.c


void check_last_log(Rotor *RotorsArr);
void save_rotor_posisions();

//INTERNAL FUNCTION FROM logging.c
void _writeLog(char *_formatted_data);



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
void change_mode(char *last_input, char *last_output, bool show);

// 
void enigma(int selected_mode, Rotor RotorsArr[4], char ArrPlug[26]);

// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                          MORSE_CODE_HEADER
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
// IMPORTANT NOTE : USEFUL INFORMATION IS IN "MorseCode.c"

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
void logging(char *input, char *output, char *stage, bool show);



#endif