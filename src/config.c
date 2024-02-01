//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                          config.c
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// co-authored.contains variable initialization and function exact
// declarations

#include "config.h"

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& ENIGMA.c

int indexof(char c, char arr[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == c)
            return i;
    }
}

int pre_reflector(Rotor *rotor, int input, int InputChar)
{

    if ((*rotor).ShiftChar == InputChar)
    {
        (*rotor).Position = ((*rotor).Position + 1) % 26;
    }

    if (input + (*rotor).Position < 0)
    {
        input = (input + (*rotor).Position) + 26;
    }
    else
    {
        input = ((*rotor).Position + input) % 26;
    }

    return ((*rotor).ArrRotor[input] - 65) - (*rotor).Position;
}

int post_reflector(Rotor *rotor, int input)
{
    if (input + (*rotor).Position < 0)
    {
        input = (input + (*rotor).Position) + 26;
    }
    else
    {
        input = ((*rotor).Position + input) % 26;
    }

    return indexof(input + 65, (*rotor).ArrRotor) - (*rotor).Position;
}

char plugboard(char c, char* arr)
{
    return arr[c - 65];
}

void config(Rotor *RotorsArr, char ArrPlug[26])
{
    int n = 5;
    Rotor *default_rotors;
    default_rotors = (Rotor *)calloc(n, (sizeof(Rotor)));

    Rotor r1 = {0, 'A', {'C', 'X', 'F', 'G', 'E', 'V', 'A', 'H', 'N', 'M', 'B', 'D', 'L', 'K', 'P', 'O', 'Z', 'T', 'Q', 'J', 'I', 'W', 'S', 'R', 'U', 'Y'}};
    Rotor r2 = {0, 'B', {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'}};
    Rotor r3 = {0, 'C', {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'}};
    Rotor r4 = {0, 'D', {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'}};
    Rotor r5 = {0, 'E', {'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N', 'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'}};
    Rotor reflector = {0, 27, {'A', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'Y', 'T'}};

    default_rotors[0] = r1;
    default_rotors[1] = r2;
    default_rotors[2] = r3;
    default_rotors[3] = r4;
    default_rotors[4] = r5;

    int first_rotor, second_rotor, third_rotor;
    int first_rotor_position, second_rotor_position, third_rotor_position;

    read_settings(n, &first_rotor, &first_rotor_position,
                        &second_rotor, &second_rotor_position,
                        &third_rotor, &third_rotor_position, ArrPlug);

    default_rotors[--first_rotor].Position  = first_rotor_position;

    default_rotors[--second_rotor].Position = second_rotor_position;

    default_rotors[--third_rotor].Position  = third_rotor_position;

    RotorsArr[0] = default_rotors[first_rotor];
    RotorsArr[1] = default_rotors[second_rotor];
    RotorsArr[2] = default_rotors[third_rotor];
    RotorsArr[3] = reflector;
}

//************************************
//     morse code initializations
//************************************

// declaration is in the header file "config.h" but the initialization is here

const char *CHAR_TO_MORSE[128] = {
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"-.-.--",
    ".-..-.",NULL,NULL,NULL,NULL,".----.","-.--.","-.--.-",NULL,
    NULL,"--..--","-....-",".-.-.-","-..-.","-----",".----","..---",
    "...--","....-",".....","-....","--...","---..","----.","---...",
    NULL,NULL,"-...-",NULL,"..--..",".--.-.",".-","-...","-.-.",
    "-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
    "-.","---",".--.","--.-",".-.","...","-","..-","...-",
    ".--","-..-","-.--","--..",NULL,NULL,NULL,NULL,"..--.-",
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};

const char *MORSE_TO_CHAR[128] = {
    NULL, NULL, "E", "T", "I", "N", "A", "M",
    "S", "D", "R", "G", "U", "K", "W", "O",
    "H", "B", "L", "Z", "F", "C", "P", NULL,
    "V", "X", NULL, "Q", NULL, "Y", "J", NULL,
    "5", "6", NULL, "7", NULL, NULL, NULL, "8",
    NULL, "/", NULL, NULL, NULL, "(", NULL, "9",
    "4", "=", NULL, NULL, NULL, NULL, NULL, NULL,
    "3", NULL, NULL, NULL, "2", NULL, "1", "0",
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, ":",
    NULL, NULL, NULL, NULL, "?", NULL, NULL, NULL,
    NULL, NULL, "\"", NULL, NULL, NULL, "@", NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, "'", NULL,
    NULL, "-", NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, ".", NULL, "_", ")", NULL, NULL,
    NULL, NULL, NULL, ",", NULL, "!", NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

// End of file