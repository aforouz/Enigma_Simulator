#ifndef configuration
#define configuration

#include <stdio.h>
#include <stdlib.h>

// Each Rotor needs the defined properties in this struct...
struct Rotor
{
    int Position;
    char ShiftChar;
    char ArrRotor[26];
};

typedef struct Rotor Rotor;

char ArrPlug[26] = {'N', 'B', 'C', 'D', 'F', 'E', 'H', 'G', 'K', 'J', 'I', 'L', 'M', 'A', 'O', 'P', 'Z', 'X', 'S', 'T', 'U', 'V', 'W', 'R', 'Y', 'Q'};
Rotor RotorsArr[4] = {{4, 'a', {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'}},
                      {26, 'A', {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'}},
                      {14, 'C', {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'}},
                      {0, 'n', {'A', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'Y', 'T'}}};

// The RotorInit function will initialize each rotor as we intend to do...
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

#endif
