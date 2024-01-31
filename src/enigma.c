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
#include "config.h"



//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//                      DRIVER_CODE
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
void enigma(int selected_mode, Rotor RotorsArr[4], char ArrPlug[26])
{
    char *output_string;
    int back;
    int former_output;
    size_t counter = 0;

    switch (selected_mode)
    {

    case (char_mode):
    {
        int back, i;
        char c;

        printf("\nEnter a single character every time, and press Enter :\n");
        printf("(If finished enter '*')\n");
        c = getch();

        while (c != '*')
        {
            c = toupper(c);
            if (!(65 <= c && c <= 90))
            {
                printf("Oh shit, wrong character, enter a valid one: (A-Z)\n");
                c = getch();
                continue;
            }

            logging(c, plugboard(c, ArrPlug), "plugin1");

            back = pre_reflector(&RotorsArr[0], plugboard(c, ArrPlug) - 65, 'a', selected_mode);

            // first rotor logging
            logging(plugboard(c, ArrPlug), back + 65, "R1");

            for (size_t i = 1; i < 4; i++)
            {
                former_output = back;
                back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].Position, selected_mode);
                logging(former_output + 65, back + 65, ("R%d", i + 1)); // goes from rotor2 to rotor4(reflect)
            }

            for (size_t i = 2; i > -1; i--)
            {
                former_output = back;
                back = post_reflector(&RotorsArr[i], back);
                logging(former_output + 65, back + 65, ("R%d", i + 2));
            }

            if (back < 0)
            {
                back += 26;
            }
            else
            {
                back %= 26;
            }

            putch(plugboard(back, ArrPlug) + 65);
        }

        break;
    }

    case (str_mode):
    {
        printf("\nEnter your string in one line , without spaces :");

        char *user_input;

        user_input = inputString(stdin, 1);
        output_string = (char *) calloc(strlen(user_input), sizeof(char));

        for (size_t j = 0; j < strlen(user_input); j++)
        {
            // scanf(" %c", c + i);

            // plugin1 logging
            logging(user_input[j], plugboard(user_input[j], ArrPlug), "plugin1");

            back = pre_reflector(&RotorsArr[0], plugboard(user_input[j], ArrPlug) - 65, 'a', selected_mode);

            // first rotor logging
            logging(plugboard(user_input[j], ArrPlug), back + 65, "R1");

            for (size_t i = 1; i < 4; i++)
            {
                former_output = back;
                back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].Position, selected_mode);
                logging(former_output + 65, back + 65, ("R%d", i + 1)); // goes from rotor2 to rotor4(reflect)
            }

            for (size_t i = 2; i > -1; i--)
            {
                former_output = back;
                back = post_reflector(&RotorsArr[i], back);
                logging(former_output + 65, back + 65, ("R%d", i + 2));
            }

            if (back < 0)
            {
                back += 26;
            }
            else
            {
                back %= 26;
            }

            output_string[counter++] = plugboard(back, ArrPlug) + 65;
            // change_mode(c[i],output_string[i]);
        }

        puts(output_string);

        break;
    }

    case (file_mode):
    {
        FILE *input_file;
        size_t file_counter = 0;
        output_string = (char *) malloc(10*sizeof(char));

        input_file = fopen("input.txt", "r");
        if (input_file == NULL)
        {
            printf("input.txt Not Found!!!");
            exit(0);
        }

        while (1)
        {
            char temp = fgetc(input_file);
            if (feof(input_file))
                break;

            if ((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z'))
            {
                if (counter == ++file_counter)
                {
                    output_string = realloc(output_string, counter+=10);
                }

                temp = toupper(temp);

                // use temp for enigma in this line
                logging(temp, plugboard(temp, ArrPlug), "plugin1");

                back = pre_reflector(&RotorsArr[0], plugboard(temp, ArrPlug) - 65, 0, selected_mode);

                // first rotor logging
                logging(plugboard(temp, ArrPlug), back + 65, "R1");

                for (size_t i = 1; i < 4; i++)
                {
                    former_output = back;
                    back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].Position, selected_mode);
                    logging(former_output + 65, back + 65, ("R%d", i + 1)); // goes from rotor2 to rotor4(reflect)
                }

                for (size_t i = 2; i > -1; i--)
                {
                    former_output = back;
                    back = post_reflector(&RotorsArr[i], back);
                    logging(former_output + 65, back + 65, ("R%d", i + 2));
                }

                if (back < 0)
                {
                    back += 26;
                }
                else
                {
                    back %= 26;
                }

                output_string[counter++] = plugboard(back, ArrPlug) + 65;

            }
        }

        fclose(input_file);
        puts(output_string);

        break;
    }

    default:
        break;
    }
}
