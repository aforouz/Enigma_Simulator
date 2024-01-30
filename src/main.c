//###############################################
//               DRIVER_CODE
//###############################################


//############################################### DECLARATIONS

#include "config.h"


int main(void)
{
    //##################CLI AND MENU
    //Show welcome page and ask password
    login();

    //Select input/output mode
    int selected_mode=select_mode();
    int former_output;

    switch (selected_mode)
    {


        case (char_mode):
        {
            // size_t n=99999999; 
            int back, i;
            char c;
            // char *c;
            // c = (char *)malloc(n * sizeof(char));

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


            }
            // for (size_t j = 0; j < strlen(c); j++)
            // {
            //     printf("Enter a character :");
            //     scanf(" %c", c + i);
                
            //     //plugin1 logging
            //     logging(c[i],plugboard(c[i],ArrPlug),plugin1);
            //     back = pre_reflector(&RotorsArr[0], plugboard(c[i], ArrPlug) - 65, 'a');
            
            //    //first rotor logging
            //     logging(plugboard(c[i],ArrPlug),back+65,"R1");

            //     for (i = 1; i < 4; i++)
            //     {
            //         back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i - 1].Position]);
            //        //first rotor logging
            //     logging(plugboard(c[i],ArrPlug),back+65,"R1");
            //     }

            //     for (i = 2; i > -1; i--)
            //     {
            //         back = post_reflector(&RotorsArr[i], back);
            //     }

            //     if (back < 0)
            //     {
            //         back += 26;
            //     }
            //     else
            //     {
            //         back %= 26;
            //     }
            //     printf("%c\n", plugboard(back + 65, ArrPlug));
            //     // change_mode(c[i],plugboard(back+65 , ArrPlug));
            // }

        break;
        }



        case (str_mode):

        {


            printf("\nEnter your string in one line , without spaces :");
            
            int back;
            char *user_input;
            user_input = inputString(stdin, 1);

            for (size_t j = 0; j < strlen(user_input); j++)
            {
                // scanf(" %c", c + i);
                
                //plugin1 logging
                logging(user_input[j],plugboard(user_input[j],ArrPlug),"plugin1");


                back = pre_reflector(&RotorsArr[0], plugboard(user_input[j], ArrPlug) - 65, 'a');

                //first rotor logging
                logging(plugboard(user_input[j],ArrPlug),back+65,"R1");


                for (i = 1; i < 4; i++)
                {
                    former_output = back;
                    back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i - 1].Position]);
                    logging(former_output+65 , back +65 , ("R%d",i+1));// goes from rotor2 to rotor4(reflect)
                }

                for (i = 2; i > -1; i--)
                {
                    former_output = back;
                    back = post_reflector(&RotorsArr[i], back);
                    logging(former_output+65 , back+65 , "R%d",i+2);
                }

                if (back < 0)
                {
                    back += 26;
                }
                else
                {
                    back %= 26;
                }

                output_string[i] = plugboard(back + 65,ArrPlug);
                // change_mode(c[i],output_string[i]);
            }
                puts(output_string);

            break;
        }


        case (file_mode):
        {
            
            size_t n=99999999, back, i;
            char *c;
            c = (char *)malloc(n+1 * sizeof(char));
            output_string = (char *)calloc(n+1 , sizeof(char));
            printf("Put * at the end of your message \n" );
            c = input();
            
            for (size_t j = 0; j < strlen(c); j++)
            {
                // scanf(" %c", c + i);
                back = pre_reflector(&RotorsArr[0], plugboard(c[i], ArrPlug) - 65, 'a');
            
                for (i = 1; i < 4; i++)
                {
                    back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i - 1].Position]);
                }

                for (i = 2; i > -1; i--)
                {
                    back = post_reflector(&RotorsArr[i], back);
                }

                if (back < 0)
                {
                    back += 26;
                }
                else
                {
                    back %= 26;
                }

                output_string[i] = plugboard(back + 65,ArrPlug);
                // change_mode(c[i],output_string);
            }

            output(output_string);//now we have the encrypted file
            
            break;
        }
    
    }

    return 0;
}
//END OF FILE
