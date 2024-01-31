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


void enigma(int selected_mode, Rotor *RotorsArr, char *ArrPlug)
{
    char *output_string;
    int back;
    int former_output;
    size_t counter = 0;

    switch (selected_mode)
    {

    case (char_mode):
    {
        int i;
        char c, back;
        char table[10];//for log_table

        printf("\nEnter a single character every time, and press Enter :\n");
        printf("(If finished enter '*')\n");
        c = getch();

        while (c != '*')
        {          
            c = toupper(c);
            table[0]=c;

            if (!(65 <= c && c <= 90))
            {
                printf("AH SHIT, wrong character, enter a valid one: (A-Z)\n");
                c = getch();
                continue;
            }

            // logging(c, plugboard(c, ArrPlug), "plugin1");
            c=plugboard(c, ArrPlug);
            table[1]=c;

            //back = pre_reflector(&RotorsArr[0], plugboard(c, ArrPlug) - 65, 'a', selected_mode);
            back = pre_reflector(&RotorsArr[0], c - 65, RotorsArr[0].ShiftChar);
            if (back < 0)back += 26;else back %= 26;
            table[2]=back+65;
            // first rotor logging
            // logging(plugboard(c, ArrPlug), back + 65, "R1");

            for (size_t i = 1; i < 4; i++)
            {
                former_output = back;
                back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i-1].Position]);
                if (back < 0)back += 26;else back %= 26;
                table[i+2]=back+65;
                //char rotor_temp[3];
                //sprintf(rotor_temp,"R%d",i+1);
                // logging(former_output + 65, back + 65, rotor_temp); // goes from rotor2 to rotor4(reflect)
            }

            for (int i = 2; i > -1; i--)
            {
                former_output = back;
                back = post_reflector(&RotorsArr[i], back);
                if (back < 0)back += 26;else back %= 26;
                table[8-i]=back+65;
                //char rotor_temp[3];
                //sprintf(rotor_temp,"R%d",i+2);
                // logging(former_output + 65, back + 65, rotor_temp);
            }

            if (back < 0)back += 26;else back %= 26;
            table[9]=plugboard(back+65,ArrPlug);

            indicate_data_generated(table);

            c = getch();
        }

        break;
    }

    case (str_mode):
    {
        //due to problems this was changed to static
        char user_input[1001],output_string[1001]={};

        gets(user_input);

        string_try:
        printf("\nEnter your string in one line , without spaces (max:1000ch):");

        gets(user_input);
        for(int i=0;i<strlen(user_input);i++)
        {
            if (!(65 <= user_input[i] && user_input[i] <= 90))
            {
                printf("AH SHIT, wrong string, enter a valid one: (A-Z)\n");
                goto string_try;
            }
        }
        
        
        //output_string = (char *) calloc(strlen(user_input), sizeof(char));

        for (size_t j = 0; j < strlen(user_input); j++)
        {
            // scanf(" %c", c + i);

            // plugin1 logging
            //logging(user_input[j], plugboard(user_input[j], ArrPlug), "plugin1");

            user_input[j]=plugboard(user_input[j], ArrPlug);

            //back = pre_reflector(&RotorsArr[0], plugboard(c, ArrPlug) - 65, 'a', selected_mode);
            back = pre_reflector(&RotorsArr[0], user_input[j] - 65, RotorsArr[0].ShiftChar);
            // first rotor logging
            // logging(plugboard(c, ArrPlug), back + 65, "R1");

            for (size_t i = 1; i < 4; i++)
            {
                former_output = back;
                back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i-1].Position]);
                //char rotor_temp[3];
                //sprintf(rotor_temp,"R%d",i+1);
                // logging(former_output + 65, back + 65, rotor_temp); // goes from rotor2 to rotor4(reflect)
            }

            for (int i = 2; i > -1; i--)
            {
                former_output = back;
                back = post_reflector(&RotorsArr[i], back);
                //char rotor_temp[3];
                //sprintf(rotor_temp,"R%d",i+2);
                // logging(former_output + 65, back + 65, rotor_temp);
            }

            if (back < 0)
            {
                back += 26;
            }
            else
            {
                back %= 26;
            }

            output_string[j]=plugboard(back+65,ArrPlug);
            output_string[j+1]='\0';
            // change_mode(c[i],output_string[i]);
        }
        

        puts(output_string);
        getch();

        break;
    }

    case (file_mode):
    {
        FILE *input_file,*output_file;

        input_file = fopen("input.txt", "r");
        if (input_file == NULL)
        {
            printf("input.txt Not Found!!!");
            exit(0);
        }

        output_file = fopen("output.txt", "w");
        if (input_file == NULL)
        {
            printf("output.txt Cant't Be Created!!!");
            exit(0);
        }

        while (1)
        {
            char temp = fgetc(input_file);
            if(temp==EOF)break;

            if ((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z'))
            {
                temp=toupper(temp);
                temp=plugboard(temp, ArrPlug);
                //back = pre_reflector(&RotorsArr[0], plugboard(c, ArrPlug) - 65, 'a', selected_mode);
                back = pre_reflector(&RotorsArr[0], temp - 65, RotorsArr[0].ShiftChar);

                // first rotor logging
                // logging(plugboard(c, ArrPlug), back + 65, "R1");

                for (size_t i = 1; i < 4; i++)
                {
                    former_output = back;
                    back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i-1].Position]);
                    //char rotor_temp[3];
                    //sprintf(rotor_temp,"R%d",i+1);
                    // logging(former_output + 65, back + 65, rotor_temp); // goes from rotor2 to rotor4(reflect)
                }

                for (int i = 2; i > -1; i--)
                {
                    former_output = back;
                    back = post_reflector(&RotorsArr[i], back);
                    //char rotor_temp[3];
                    //sprintf(rotor_temp,"R%d",i+2);
                    // logging(former_output + 65, back + 65, rotor_temp);
                }

                if (back < 0)
                {
                    back += 26;
                }
                else
                {
                    back %= 26;
                }

                fprintf(output_file,"%c",plugboard(back+65,ArrPlug));
                
            }
        }

        fclose(input_file);
        fclose(output_file);

        break;
    }

    default:
        break;
    }
}
