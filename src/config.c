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



void rotorinit(Rotor *rotor_array)//IMPORTANT : Adding or removing a rotor
{
    size_t n = 5;
    Rotor *default_rotors;

    default_rotors = (Rotor*)calloc(n, (sizeof(Rotor)));

//This version has five rotors and the user can either pick one or manually build one.... .

//A sample of five rotors pre-initialized..
    Rotor r1 = {1, 'A', {'C', 'X', 'F', 'G', 'E', 'V', 'A', 'H', 'N', 'M', 'B', 'D', 'L', 'K', 'P', 'O', 'Z', 'T', 'Q', 'J', 'I', 'W', 'S', 'R', 'U', 'Y'}};
    Rotor r2 = {1, 'A', {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'}};
    Rotor r3 = {1, 'A', {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'}};
    Rotor r4 = {1, 'A', {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'}};
    Rotor r5 = {1, 'A', {'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N', 'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'}};

//we cant access the arguments within a struct directly so we use strcpy
    strcpy(default_rotors[0],r1);
    strcpy(default_rotors[1],r2);
    strcpy(default_rotors[2],r3);
    strcpy(default_rotors[3],r4);
    strcpy(default_rotors[4],r5);


    int user_input = 2;
    printf("Enter 0 for adding or 1 for removing rotors, if none enter 2: ");
    scanf("%d", &user_input);

    switch (user_input)
    {
        //0 is for adding
        //1 is for removing
        //2 is for quit/exit
    case (0):
        //adding a rotor
    {
        char new_rotor_arr[26];
        printf("Enter the character you want to connect to:\n");
        for (int i = 0; i < 26; i++)
        {

            char c;
            printf("%c", i+65);
            scanf(" %c", &c);
            while (!(65 <= c+65 && c+65 <= 90))// As long as the input is not valid continue this cycle
            {
                printf("%c: ", i+65);
                scanf(" %c", &c);
            }

            new_rotor_arr[i] = c;
        }
        Rotor new_rotor = {1, 'A', *new_rotor_arr};

        default_rotors = (Rotor*)realloc(default_rotors, n+1);//adding another memory portion for default rotors

        strcpy(default_rotors[n+1],new_rotor);//strcpy 

        break;
    }

    case(1):
    {
        int index = -1;
        printf("Which one do you want to remove? (enter a number between 1 and 5)\n");
        scanf("%d", &index);

        index -= 1;
        while(!(0 <= index && index <= 5))
        {
            printf("Enter a valid number! (1 <= x <= 5)");
            scanf("%d", &index);
        }

        Rotor *null_rotor = NULL;
        strcpy(default_rotors[index],*null_rotor);

        break;
    }

    default:
        printf("\nThe entry was not valid\n");
        break;
    }

    int a, b, c;
    int fisrt, second;
    int position_r1, position_r2, position_r3;
    char second_shift_char, third_shift_char;

    printf("Which rotors do you want to pick? (enter 3 numbers between 1 and %d): ", n+1);
    scanf("%d %d %d", &a, &b, &c);

    printf("Which of these rotors do you want to pick first? (enter that rotors number): ");
    scanf("%d", &fisrt);

    printf("And second: ");
    scanf("%d", &second);

    printf("OK, now enter the number position of the first rotor: ");
    scanf("%d", position_r1);

    printf("OK, now enter the number position of the second rotor: ");
    scanf("%d", position_r2);

    printf("OK, now enter the number position of the third rotor: ");
    scanf("%d", position_r3);

    printf("Now enter the shift character for the second rotor: ");
    scanf(" %c", &second_shift_char);

    printf("And the shift character for the third rotor: ");
    scanf(" %c", &third_shift_char);

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