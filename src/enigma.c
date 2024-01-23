//      The quieter you become,the more are able to hear... .KALI_LINUX BY RUMI


//MAIN_ALGORITHM_FOR_ENIGMA_CODE

// @tile   : Main algorithm
// @author : CO-authored..
// @notice : the algorithm works fine,but it is not optimized
//           and it will be changed... .
// @dev    : Function prototypes are provided in the headers
// @custom : None


//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//                      DECLARATIONS
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
#include "config.c"



//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//                      DRIVER_CODE
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
int main(void)
{
    int n, back, i;
    char *c;
    c = (char *)malloc(n * sizeof(char));
    scanf("%d", &n);



    for (int j = 0; j < n; j++)
    {
        scanf(" %c", c + i);
        back = ThroughRotorCall(&RotorsArr[0], PlugBoard(c[i], ArrPlug) - 65, 'a');
        // printf("%c\n", c[i]);
        for (i = 1; i < 4; i++)
        {
            back = ThroughRotorCall(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i - 1].Position]);
        }

        for (i = 2; i > -1; i--)
        {
            back = BackRotorCall(&RotorsArr[i], back);
        }

        if (back < 0)
        {
            back += 26;
        }
        else
        {
            back %= 26;
        }
        printf("OUTPUT: %c\n", PlugBoard(back + 65, ArrPlug));
    }
    return 0;
}
