#include "../src/config.h"

// test for pre reflector.
// Author : A.Jafari
// Notice that function prototypes are provided in the headers.

int main()
{
    Rotor rotor1 = { 0, 0, {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'} };
    int input = 3;
    int inputChar = 67;

    printf("Before: %c\n", rotor1.ArrRotor[input]);
    pre_reflector(&rotor1, input, inputChar);
    printf("After: %c\n", rotor1.ArrRotor[input]);

    return 0;
}
