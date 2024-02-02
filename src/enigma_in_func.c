//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                        ENIGMA_IN_FUNC
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// @title   :  Enigma_In_Func                 USAGE_EXAMPLE-INCLUDED
// @author  :  Ahmadi                           
// @dev     :  Usage example is included at the end of file
//             this function is an example of how ENIGMA works
//             and therefore not much configuration can be done..
//             but this can be used for a quick encryption or
//             decryption 
// @notice  :  For changing the configuration you have to do it
//             manually in this source file  
// @function prototype : const char* enigma_in_func(char *c)

//first_part
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Each Rotor needs the defined properties in this struct...

struct Rotor
{
    int Position;
    char ShiftChar;
    char ArrRotor[26];
};

typedef struct Rotor Rotor;
// The RotorInit function will initialize each rotor as we intend to do...
void Rinit(Rotor rotor, int P, int Rnum, char array[]);

// RotorCall, does the math required to calculate the output character of the specified rotor...
int ThroughRotorCall(Rotor *rotor, int Input, char InputChar);

// This function is used to configure the Rotors and the Plugboard to encode or decode a letter...
void config(Rotor rotors[], char PlugBoard[]);

//second_part

int IndexOf(char c, char arr[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == c)
            return i;
    }
}

int ThroughRotorCall(Rotor *rotor, int input, char InputChar)
{
    if ((*rotor).ShiftChar == InputChar)
    {
        (*rotor).Position = ((*rotor).Position+1) % 26;
    }

    if (input+(*rotor).Position < 0)
    {
        input = (input + (*rotor).Position) + 26;
    }
    else
    {
        input = ((*rotor).Position + input) % 26;
    }

    return ((*rotor).ArrRotor[input] - 65) - (*rotor).Position;
}

int BackRotorCall(Rotor *rotor, int input)
{
    if (input+(*rotor).Position < 0)
    {
        input = (input + (*rotor).Position) + 26;
    }
    else
    {
        input = ((*rotor).Position + input) % 26;
    }

    return IndexOf(input+65, (*rotor).ArrRotor) - (*rotor).Position;
}

//Function i wrote :
// #define DEBUG_OUTPUT 
char* enigma_in_func(char *c, int _n)
{
    Rotor R1 = {0, 'a', {'E', 'K', 'M','F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'}};
    Rotor R2 = {0, 'A', {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'}};
    Rotor R3 = {0, 'C', {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'}};
    Rotor Ref = {0, 'n', {'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T'}};

    int i = 0 ;
    char *encypted_data = (char*) calloc(_n , sizeof(char));
    

    for (int i = 0; c[i]; i++)
    {
        int out = ThroughRotorCall(&R1, c[i]-65, 'a');
        int out2 = ThroughRotorCall(&R2, out, R1.ArrRotor[R1.Position]);
        int out3 = ThroughRotorCall(&R3, out2, R2.ArrRotor[R2.Position]);
        int outRef = ThroughRotorCall(&Ref, out3, 'a');
        int back = BackRotorCall(&R3, outRef);
        int back2 = BackRotorCall(&R2, back);
        int back3 = BackRotorCall(&R1, back2);
        if (back3 < 0)
        {
            back3 += 26;
        }
        else
        {
            back3 %= 26;
        }
        #ifdef DEBUG_OUTPUT
        printf("%c", back3+65);
        #endif

        encypted_data[i] = back3+65;
    }
    return encypted_data;
}
