#include "../src/config.h"

// test for post reflector.
// Author : A.Jafari
// Notice that function prototypes are provided in the headers.

int main()
{
    Rotor rotor1 = { 0, 0, {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'} };
    int input = 3;

    printf("Before: %c\n", rotor1.ArrRotor[input]);
    post_reflector(&rotor1, input);
    printf("After: %c\n", rotor1.ArrRotor[input]);

    return 0;
}
