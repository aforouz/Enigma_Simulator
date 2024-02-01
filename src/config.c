//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                          config.c
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// co-authored.contains variable initialization and function exact
// declarations

#include "config.h"

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& ENIGMA.c

// variables getting initialized
// these are marked with extern in the header file, used in enigma.c ...
// char ArrPlug[26] = {'N', 'B', 'C', 'D', 'F', 'E', 'H', 'G', 'K', 'J', 'I', 'L', 'M', 'A', 'O', 'P', 'Z', 'X', 'S', 'T', 'U', 'V', 'W', 'R', 'Y', 'Q'};

// this is our reflector
// Rotor RotorsArr[4] = {0, 'n', {'A', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'Y', 'T'}};

int indexof(char c, char arr[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == c)
            return i;
    }
}

char *inputString(FILE *fp, size_t size)
{
    // The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str) * size); // size is start size
    if (!str)
        return str;
    while (EOF != (ch = fgetc(fp)) && ch != '\n')
    {
        str[len++] = ch;
        if (len == size)
        {
            str = realloc(str, sizeof(*str) * (size += 16));
            if (!str)
                return str;
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(*str) * len);
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

void add_remove_rotor(Rotor *default_rotors, int *n)
{
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
                *n += 1;
                Rotor new_rotor = {1, -1, *new_rotor_arr};
                default_rotors = (Rotor *)realloc(default_rotors, *n);
                default_rotors[*n] = new_rotor;

                break;
            }

        case (1):
        {
            // removing a rotor
            int index = -1;
            printf("Which one do you want to remove? (enter a number between 1 and 5)\n");
            scanf("%d", &index);

            index -= 1;
            while (!(0 <= index && index <= *n))
            {
                printf("Enter a valid number! (1 <= x <= 5)");
                scanf("%d", &index);
            }

            default_rotors[index].Position = -1;

            break;
        }

        default:
            break;
        }
    }
}

void rotorinit(Rotor rotor_array[3], Rotor *default_rotors, int n)
{
    int first_rotor = 0, second_rotor = 0, third_rotor = 0;
    int first_rotor_position = 0, second_rotor_position = 0, third_rotor_position = 0;
    int second_rotor_shift = 0, third_rotor_shift = 0;

    printf("Which rotor do you want to use as the first one? (Choose a number between 1 and %d)\n", n);
    while (!(1 <= first_rotor && first_rotor <= n) &&
           (default_rotors[first_rotor].Position != -1))
    {
        printf("Please enter a valid number that is not removed (1 <= number <= %d)\n", n);
        scanf("%d", &first_rotor);
    }

    printf("GREAT, now enter the number of second rotor you want to use:\n");
    while (!(1 <= second_rotor && second_rotor <= n) &&
           second_rotor != first_rotor &&
           (default_rotors[second_rotor].Position != -1))
    {
        printf("Don't forget to enter a valid number! (1 <= number <= %d and not equal to first rotor and not removed)\n",n);
        scanf("%d", &second_rotor);
    }

    printf("Now it's time to choose which rotor to use for the third rotor:\n");
    while (!(1 <= third_rotor && third_rotor <= n) &&
           third_rotor != first_rotor &&
           third_rotor != second_rotor &&
           (default_rotors[third_rotor].Position != -1))
    {
        printf("Just a reminder to enter a valid number! (1 <= number <= %d and not equal to first and second rotor)\n",n);
        scanf("%d", &third_rotor);
    }

    printf("Do me a favor and enter the first rotor's position number: (it should be between 1 and 26):\n");
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
        printf("THE NUMBER SHOULD BE BETWEEN 1 AND 26, REMEMBER!\n");
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

    first_rotor -= 1;
    second_rotor -= 1;
    third_rotor -= 1;

    first_rotor_position -= 1;
    second_rotor_position -= 1;
    third_rotor_position -= 1;

    second_rotor_shift -= 1;
    third_rotor_shift -= 1;

    default_rotors[first_rotor].Position = first_rotor_position;
    default_rotors[first_rotor].ShiftChar = 'a';

    default_rotors[second_rotor].Position = second_rotor_position;
    default_rotors[second_rotor].ShiftChar = second_rotor_shift;

    default_rotors[third_rotor].Position = third_rotor_position;
    default_rotors[third_rotor].ShiftChar = third_rotor_shift;

    Rotor reflector = {0, 27, {'A', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'Y', 'T'}};

    rotor_array[0] = default_rotors[first_rotor];
    rotor_array[1] = default_rotors[second_rotor];
    rotor_array[2] = default_rotors[third_rotor];
    rotor_array[3] = reflector;

    return;
}

void plugboard_init(char plug_arr[26])
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

        // a -= 65;
        // b -= 65;

        plug_arr[a] = b;
        plug_arr[b] = a;
    }

    return;
}

int select_settings()
{
    int input=0,menu=1;

    while(1)
    {
        if(input==27)//Esc key
        {
            printf("\n\nProgram Exited! Bye:)");
            exit(0);
        }
        if(input==13)break;
        if(input==80)menu++;
        if(input==72)menu--;
        if(menu>2)menu=1;
        if(menu==0)menu=2;

        system("cls");

        printf("\x1B[33mHow Do You Want Set Settings?\n");     
        printf("Use Up/Down Key And Press Enter Or Esc\x1B[0m\n\n");

        if(menu==1)printf("\x1B[32m-> ");else printf("\x1B[0m   ");
        printf("Import From Settings.txt\n");

        if(menu==2)printf("\x1B[32m-> ");else printf("\x1B[0m   ");
        printf("Enter Manually\n");
        printf("\x1B[0m   ");

        input=getch();
    }

    return menu;
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

    // //getting the setting from log
    // File *config_loading_conf_c ;
    // config_loading_conf_c = fopen("../logs/machine_logs.log", "r");//try to open the log
    // if(config_loading_conf_c !=NULL)//if the log wasnt empty:then read 


     add_remove_rotor(default_rotors, &n);

    int settings_mode = select_settings();

    switch (settings_mode)
    {
    case file_set:
        int first_rotor, second_rotor, third_rotor;
        int first_rotor_position, second_rotor_position, third_rotor_position;


        read_settings(n, &first_rotor, &first_rotor_position,
                          &second_rotor, &second_rotor_position,
                          &third_rotor, &third_rotor_position, ArrPlug);
        
        if (default_rotors[--first_rotor].Position == -1)
        {
            printf("The %d rotor you chose was deleted!\n", first_rotor + 1);
            exit(0);
        }

        if (default_rotors[--second_rotor].Position == -1)
        {
            printf("The %d rotor you chose was deleted!\n", second_rotor + 1);
            exit(0);
        }

        if (default_rotors[--third_rotor].Position == -1)
        {
            printf("The %d rotor you chose was deleted!\n", third_rotor + 1);
            exit(0);
        }

        default_rotors[first_rotor].Position  = first_rotor_position;

        default_rotors[second_rotor].Position = second_rotor_position;

        default_rotors[third_rotor].Position  = third_rotor_position;

        RotorsArr[0] = default_rotors[first_rotor];
        RotorsArr[1] = default_rotors[second_rotor];
        RotorsArr[2] = default_rotors[third_rotor];
        RotorsArr[3] = reflector;


        break;

    case manual_set:
    {
        rotorinit(RotorsArr, default_rotors, n);
        plugboard_init(ArrPlug);

        break;
    }

    default:
        break;
    }

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