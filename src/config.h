//// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= decleartions
#ifndef configuration
#define configuration

#include <stdio.h>
#include <stdlib.h>





// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                      Rotor_Data_Type
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//   Each Rotor needs the defined properties in this struct...
struct Rotor
// @title:  Rotor data type decleration... 
// @author: Mohammad Siamaki
// @notice: This struct can be modified later... .
// @dev   : every Rotor has a starting position called "position",
//          an indicator for shifting called "ShiftChar",
//          and values on the out put i.e "ArrRotor"... .
//@custom : we assume that the reflector is a constant rotor so we have 4 rotors
{
    int Position;
    char ShiftChar;
    char ArrRotor[26];//Every rotor has a set of 26 possible outputs i.e. "A-->z"
};
typedef struct Rotor Rotor;//unpro naming but anyway we call our instances "Rotor" 


Rotor RotorsArr[4] = {{4, 'a', {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'}},
                      {26, 'A', {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'}},
                      {14, 'C', {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'}},
                      {0, 'n', {'A', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'Y', 'T'}}};





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

char ArrPlug[26] = {'N', 'B', 'C', 'D', 'F', 'E', 'H', 'G', 'K', 'J', 'I', 'L', 'M', 'A', 'O', 'P', 'Z', 'X', 'S', 'T', 'U', 'V', 'W', 'R', 'Y', 'Q'};




// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                     Function_Prototypes
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//                   i.e. : func declerations


// The RotorInit function will initialize each rotor as we intend to do...
//for initializing  the rotor individual we use the func below... .
//does not return anything  
//stands for "position"
//C for "Shift Char"
//array for output values
void Rotorinit(int P, char C, char array[]);



// IndexOf returns the index of an element in an array...
int IndexOf(char c, char arr[]);

// ThroughRotorCall, does the math required to calculate the output character of the specified rotor...
int ThroughRotorCall(Rotor *rotor, int Input, char InputChar);

// BackRotorCall goes back from the reflector to the first rotor...
int BackRotorCall(Rotor *rotor, int input);

// PlugBoard is called twice: Once after the character is typed and once after looping through and back the rotors...
char PlugBoard(char c, char arr[]);

// This function is used to configure the Rotors and the Plugboard, to encode or decode a letter...
void Config();



#endif//Enjoy the comment system
//thanks Solidity :D  


//End of file... .