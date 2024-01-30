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


        case (char_mode)
        {

            size_t n=99999999;, back, i;
            char *c;
            c = (char *)malloc(n * sizeof(char));

            printf("\nEnter a single character every time, and press Enter :\n");
            for (size_t j = 0; j < n; j++)
            {
                printf("Enter a character :");
                scanf(" %c", &(c + i));
                
                //plugin1 logging
                logging(c[i],plugboard(c[i],ArrPlug),plugin1);
                back = pre_reflector(&RotorsArr[0], plugboard(c[i], ArrPlug) - 65, 'a');
            
               //first rotor logging
                logging(plugboard(c[i],ArrPlug),back+65,"R1");

                for (i = 1; i < 4; i++)
                {
                    back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i - 1].Position]);
                   //first rotor logging
                logging(plugboard(c[i],ArrPlug),back+65,"R1");
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
                // change_mode(c[i],plugboard(back+65 , ArrPlug));
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
                
                //plugin1 logging
                logging(c[i],plugboard(c[i],ArrPlug),plugin1);


                back = pre_reflector(&RotorsArr[0], plugboard(c[i], ArrPlug) - 65, 'a');

                //first rotor logging
                logging(plugboard(c[i],ArrPlug),back+65,"R1");


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
            FILE *input_file;

            input_file=fopen("input.txt","r");
            if(input_file==NULL)
            {
                printf("input.txt Not Found!!!");
                exit(0);
            }

            while(1)
            {
                char temp=fgetc(input_file);
                if(feof(input_file))break;

                if((temp>='A' && temp<='Z') || (temp>='a' && temp<='z'))
                {
                    temp=toupper(temp);

                    //use temp for enigma in this line
                }               
            }

            fclose(input_file);          
            break;
        }
    
    }

    return 0;
}
}//END OF FILE
