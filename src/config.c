#include "config.h"


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

int BackRotorCall(Rotor *rotor, int input)
{
    if (input + (*rotor).Position < 0)
    {
        input = (input + (*rotor).Position) + 26;
    }
    else
    {
        input = ((*rotor).Position + input) % 26;
    }

    return IndexOf(input + 65, (*rotor).ArrRotor) - (*rotor).Position;
}

char PlugBoard(char c, char arr[])
{
    return arr[c - 65];
}
