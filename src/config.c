//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                          config.c
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//co-authored.contains variable initialization and function exact
//declarations 

#include "config.h"




//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& ENIGMA.c


//variables getting initialized
//these are marked with extern in the header file, used in enigma.c ...
char ArrPlug[26] = {'N', 'B', 'C', 'D', 'F', 'E', 'H', 'G', 'K', 'J', 'I', 'L', 'M', 'A', 'O', 'P', 'Z', 'X', 'S', 'T', 'U', 'V', 'W', 'R', 'Y', 'Q'};

//this is our reflector
Rotor RotorsArr[4] = {0, 'n', {'A', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'Y', 'T'}};


int indexof(char c, char arr[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == c)
            return i;
    }
}

int pre_reflector(Rotor *rotor, int input, char InputChar, int check)
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

int post_reflector(Rotor *rotor, int input, int check)
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

char plugboard(char c, char arr[], int check)
{
    return arr[c - 65];
}

void rotorinit(Rotor *rotor_array)
{
    int n = 5;
    Rotor *default_rotors;

    default_rotors = (Rotor *)calloc(n, (sizeof(Rotor)));

    Rotor r1 = {0, -1, {'C', 'X', 'F', 'G', 'E', 'V', 'A', 'H', 'N', 'M', 'B', 'D', 'L', 'K', 'P', 'O', 'Z', 'T', 'Q', 'J', 'I', 'W', 'S', 'R', 'U', 'Y'}};
    Rotor r2 = {0, -1, {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'}};
    Rotor r3 = {0, -1, {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'}};
    Rotor r4 = {0, -1, {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'}};
    Rotor r5 = {0, -1, {'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N', 'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'}};

    default_rotors[0] = r1;
    default_rotors[1] = r2;
    default_rotors[2] = r3;
    default_rotors[3] = r4;
    default_rotors[4] = r5;

    int user_input = -1;

    while (user_input != 2)
    {
        printf("Enter 0 for adding or 1 for removing rotors, if none enter 2: ");
        scanf("%d", &user_input);

        switch (user_input)
        {
            // 0 is for adding
            // 1 is for removing
        case (0):
            // adding a rotor
            {
                int new_rotor_arr[26];
                printf("Enter the character you want to connect to:\n");

                for (int i = 0; i < 26; i++)
                {
                    char c;
                    printf("%c", i + 65);
                    scanf(" %c", &c);
                    c = toupper(c);

                    while (!(65 <= c && c <= 90))
                    {
                        printf("%c: ", i + 65);
                        scanf(" %c", &c);
                    }

                    new_rotor_arr[i] = c - 65;
                }
                n += 1;
                Rotor new_rotor = {1, -1, *new_rotor_arr};
                default_rotors = (Rotor *)realloc(default_rotors, n);
                default_rotors[n] = new_rotor;

                break;
            }

        case (1):
        {
            // removing a rotor
            int index = -1;
            printf("Which one do you want to remove? (enter a number between 1 and 5)\n");
            scanf("%d", &index);

            index -= 1;
            while (!(0 <= index && index <= 5))
            {
                printf("Enter a valid number! (1 <= x <= 5)");
                scanf("%d", &index);
            }

            Rotor *null_rotor = NULL;
            default_rotors[index] = *null_rotor;

            break;
        }

        default:
            break;
        }
    }

    int first_rotor = 0, second_rotor = 0, third_rotor = 0;
    int first_rotor_position = 0, second_rotor_position = 0, third_rotor_position = 0;
    int second_rotor_shift = 0, third_rotor_shift = 0;

    printf("Which rotor do you want to use as the first one? (Choose a number between 1 and %d)\n", n + 1);
    while (!(1 <= first_rotor && first_rotor <= n))
    {
        printf("Please enter a valid number (1 <= number <= %d)\n", n);
        scanf("%d", &first_rotor);
    }

    printf("GREAT, now enter the number of second rotor you want to use:\n");
    while (!(1 <= second_rotor && second_rotor <= n) &&
           second_rotor != first_rotor)
    {
        printf("Don't forget to enter a valid number! (1 <= number <= %d and not equal to first rotor)\n");
        scanf("%d", &second_rotor);
    }

    printf("Now it's time to choose which rotor to use for the third rotor:\n");
    while (!(1 <= second_rotor && 
           second_rotor <= n) &&
           third_rotor != first_rotor &&
           third_rotor != second_rotor)
    {
        printf("Just a reminder to enter a valid number! (1 <= number <= %d and not equal to first and second rotor)\n");
        scanf("%d", third_rotor);
    }

    printf("Do me a favor and enter the first rotor's position number: (it should be between 1 and 27):\n");
    while (!(1 <= first_rotor_position &&
           first_rotor_position <= 26))
    {
        printf("It feels good to enter a valid number, TRUST ME! (1 <= the number you enter <= 26)\n");
        scanf("%d", &first_rotor_position);
    }

    printf("How about you enter the second rotor's position number?\n");
    while (!(1 <= second_rotor_position &&
           second_rotor_position <= 26))
    {
        printf("Here to let you know to enter a valid number... (1 <= the number you enter <= 26)\n");
        scanf("%d", &second_rotor_position);
    }

    printf("Now enter the last (third) rotor's position number:\n");
    while (!(1 <= third_rotor_position &&
           third_rotor_position <= 26))
    {
        printf("THE NUMBER SHOULD BE BETWEEN 1 AND 27, REMEMBER!\n");
        scanf("%d", &third_rotor_position);
    }

    printf("You doin GREAT!\nNow enter the shift number for the second rotor: (1 <= input number <= 26)\n");
    while (!(1 <= second_rotor_shift && 
           second_rotor_shift <= 26))
    {
        printf("People who enter a valid number live longer, that's a FACT! (1 <= input number <= 26)\n");
        scanf("%d", &second_rotor_shift);
    }

    printf("One more step to initialize the rotors!\nEnter the shift number for the third rotor:\n");
    while (!(1 <= third_rotor_shift && 
           third_rotor_shift <= 26))
    {
        printf("Validating your input is a pain in the butt! So please enter a valid character. (1 <= input number <= 26)\n");
        scanf("%d", &third_rotor_shift);
    }

    first_rotor  -= 1;
    second_rotor -= 1;
    third_rotor  -= 1;

    first_rotor_position  -= 1;
    second_rotor_position -= 1;
    third_rotor_position  -= 1;

    second_rotor_shift -= 1;
    third_rotor_shift  -= 1;

    default_rotors[first_rotor].Position  = first_rotor_position;
    default_rotors[first_rotor].ShiftChar = 'a';

    default_rotors[second_rotor].Position  = second_rotor_position;
    default_rotors[second_rotor].ShiftChar = second_rotor_shift;

    default_rotors[third_rotor].Position  = third_rotor_position;
    default_rotors[third_rotor].ShiftChar = third_rotor_shift;

    Rotor reflector = {0, 27, {'A', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'Y', 'T'}};

    rotor_array[0] = default_rotors[first_rotor];
    rotor_array[1] = default_rotors[second_rotor];
    rotor_array[2] = default_rotors[third_rotor];
    rotor_array[3] = reflector;

    return;
}

int* plugboard_init(int plug_arr[26])
{
    char a, b;
    int check = 1;

    for (int i = 0; i < 26; i++)
    {
        plug_arr[i] = i;
    }

    printf("Currently there is no wire connected to the plugboard\nAs you wish you can connect any two letters together!\nNow enter the letters you want to connect to each other like this -> XY\n(enter them in one line without any space between them)\n");

    while (1)
    {
        printf("If you don't want to connect wires enter 0: ");
        scanf("%d", &check);

        if (check == 0)
            break;
        
        printf("OK, now enter the characters as said (XY):\n");
        scanf(" %c%c", &a, &b);

        a = toupper(a);
        b = toupper(b);

        while (!(65 <= a && a <= 90) || 
               !(65 <= b && b <= 90))
        {
            printf("Do me a favor and enter them correctly! (letters form A-Z)");
            scanf(" %c%c", &a, &b);
            a = toupper(a);
            b = toupper(b);
        }

        a -= 65;
        b -= 65;

        plug_arr[a] = b;
        plug_arr[b] = a;
    }

    return plug_arr;
}


//************************************
//     morse code initializations
//************************************

//declaration is in the header file "config.h" but the initialization is here

const char *CHAR_TO_MORSE[128] = {
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
            NULL, "-.-.--", ".-..-.", NULL, NULL, NULL, NULL, ".----.",
            "-.--.", "-.--.-", NULL, NULL, "--..--", "-....-", ".-.-.-", "-..-.",
            "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
            "---..", "----.", "---...", NULL, NULL, "-...-", NULL, "..--..",
            ".--.-.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
            "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
            ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
            "-..-", "-.--", "--..", NULL, NULL, NULL, NULL, "..--.-",
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    };

const char* MORSE_TO_CHAR[128] = {
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

//End of file