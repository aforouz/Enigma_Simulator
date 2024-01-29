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

    switch (selected_mode)
    {


        case (char_mode)
        {

            size_t n=99999999;, back, i;
            char *c;
            c = (char *)malloc(n * sizeof(char));

            printf("\nEnter a single character every time, and press Enter :\n");
            for (size_t j = 0; j < n; j++)
            {
                printf("Enter a character :");
                scanf(" %c", c + i);
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
                printf("%c\n", plugboard(back + 65, ArrPlug));
            }

        break;
        }



        case (str_mode)

        {


            size_t n=99999999, back, i;
            char *c;
            c = (char *)malloc(n+1 * sizeof(char));
            output_string = (char *)calloc(n+1 , sizeof(char));

            printf("\nEnter your string in one line , without spaces :");
            gets(c);
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
                
            }
                puts(output_string);

            break;
        }


        case (file_mode)
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

                output_string[i] = plugboard(back + 65,ArrPlug)
            }
            output(output_string);
            break;
        }
    
    }

    return 0;
}
}//END OF FILE
