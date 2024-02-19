#include "../src/config.h"

// @title test for plugboard.
// @author A.Jafari
// @note Notice that function prototypes are provided in the headers.
void test_plug()
{
    char ArrPlug[26] = {'N', 'B', 'C', 'D', 'F', 'E', 'H', 'G', 'K', 'J', 'I', 'L', 'M', 'A', 'O', 'P', 'Z', 'X', 'S', 'T', 'U', 'V', 'W', 'R', 'Y', 'Q'};
    char t;
    t = plugboard('A', ArrPlug);
    if (t == ArrPlug['A' - 65])
    {
        printf("Plugboard Test : Passed!\n");
    }
    else
    {
        printf("Plugboard Test : Failed!\n");
    }
}

int main()
{
    test_plug();
    return 0;
}