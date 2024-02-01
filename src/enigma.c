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
        char c, back,plug_board_temp[10],string_temp[10],string_temp_R1[10],string_temp_R2[10];
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

            plug_board_temp[0] = plugboard(c,ArrPlug);
            string_temp[0] = c;
            string_temp[1]  = '\0';
            
            change_mode(string_temp,plug_board_temp);
            c=plugboard(c, ArrPlug);
            
            table[1]=c;

            
            back = pre_reflector(&RotorsArr[0], c - 65, RotorsArr[0].ShiftChar);
            if (back < 0)back += 26;else back %= 26;
            table[2]=back+65;
            string_temp_R1[0] = back+65;
            string_temp_R1[1] = '\0';

            logging(string_temp , string_temp_R1,"R1");//logging for first rotor
            // now str_temp is user input 
            //  str_temp_R1 is the output 
            
            for (size_t i = 1; i < 4; i++)
            {
                
                back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i-1].Position]);
                if (back < 0)back += 26;else back %= 26;
                table[i+2]=back+65;

                string_temp_R2 [0] = back+65;
                string_temp_R2 [1] = '\0';

                if( i  == 1){logging(string_temp_R1 , string_temp_R2 ,"R2");string_temp_R1[0] = string_temp_R2[0];}

                if( i  ==2 ){logging(string_temp_R1 ,string_temp_R2,"R3");  string_temp_R1[0] = string_temp_R2[0];}

                if( i  == 3){logging(string_temp_R1 ,string_temp_R2,"Ref");string_temp_R1[0] = string_temp_R2[0];}

                
            }
            
                        
            for (int i = 2; i > -1; i--)
            {
                former_output = back;
                back = post_reflector(&RotorsArr[i], back);
                if (back < 0)back += 26;else back %= 26;
                table[8-i]=back+65;

                string_temp_R2 [0] = back+65;
                string_temp_R2 [1] = '\0';

                if( i == 2 ){logging(string_temp_R1 ,string_temp_R2 ,"R3"); string_temp_R1[0] =string_temp_R2[0];}

                if( i == 1 ){logging(string_temp_R1 ,string_temp_R2 ,"R2"); string_temp_R1[0] = string_temp_R2[0];}

                if( i == 0 ){logging(string_temp_R1 ,string_temp_R2 ,"R1"); string_temp_R1[0] = string_temp_R2[0];}
                
            }

            if (back < 0)back += 26;else back %= 26;
            back +=65;

            string_temp_R1[0] = back;
            string_temp_R1[1] = '\0';

            logging(string_temp , string_temp_R1,"R1");//logging for first rotor
            // now str_temp is user input 
            //  str_temp_R1 is the output

            
            plug_board_temp[0] = plugboard(back , ArrPlug);
            string_temp[0] = back;
            change_mode(string_temp , plug_board_temp);
            table[9]=plugboard(back,ArrPlug);

            indicate_data_generated(table);

            c = getch();
        }

        break;
    }

    case (str_mode):
    {
        //due to problems this was changed to static
        char user_input[1001],output_string[1001]={};
        char c, back,plug_board_temp[10],string_temp[10],string_temp_R1[10],string_temp_R2[10];

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
        
        
        

        for (size_t j = 0; j < strlen(user_input); j++)
        {
            
            
            string_temp [0] = user_input[j];
            string_temp [1] ='\0';//now char entered by user is in string_tmp

            plug_board_temp[0] = plugboard(user_input[j] , ArrPlug);
            plug_board_temp[1] ='\0'; //now char outed by plug is in plug_board_temp

            user_input[j]=plugboard(user_input[j], ArrPlug);
            
            
            //change mode to on
            change_mode(string_temp,plug_board_temp);
            
            
            back = pre_reflector(&RotorsArr[0], user_input[j] - 65, RotorsArr[0].ShiftChar);
            string_temp_R1[0] = back+65;
            string_temp_R1[1] = '\0';
            logging(plug_board_temp , string_temp_R1 , "R1");
            

            for (size_t i = 1; i < 4; i++)
            {
                former_output = back;
                back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i-1].Position]);
                
                //
                string_temp_R2 [0] = back+65;
                string_temp_R2 [1] = '\0';

                if( i  == 1){logging(string_temp_R1 , string_temp_R2 ,"R2");string_temp_R1[0] = string_temp_R2[0];}

                if( i  ==2 ){logging(string_temp_R1 ,string_temp_R2,"R3");  string_temp_R1[0] = string_temp_R2[0];}

                if( i  == 3){logging(string_temp_R1 ,string_temp_R2,"Ref");string_temp_R1[0] = string_temp_R2[0];}
                
            }

            for (int i = 2; i > -1; i--)
            {
                former_output = back;
                back = post_reflector(&RotorsArr[i], back);
                //char rotor_temp[3];
                //sprintf(rotor_temp,"R%d",i+2);
                // logging(former_output + 65, back + 65, rotor_temp);
                string_temp_R2 [0] = back+65;
                string_temp_R2 [1] = '\0';

                if( i == 2 ){logging(string_temp_R1 ,string_temp_R2 ,"R3"); string_temp_R1[0] =string_temp_R2[0];}

                if( i == 1 ){logging(string_temp_R1 ,string_temp_R2 ,"R2"); string_temp_R1[0] = string_temp_R2[0];}

                if( i == 0 ){logging(string_temp_R1 ,string_temp_R2 ,"R1"); string_temp_R1[0] = string_temp_R2[0];}
            }

            if (back < 0)
            {
                back += 26;
            }
            else
            {
                back %= 26;
            }

            
            plug_board_temp[0] = plugboard(back+65 , ArrPlug);
            string_temp[0] = back+65;
            string_temp[1] = '\0';
            change_mode(string_temp , plug_board_temp);
            
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
            char c, back,plug_board_temp[10],string_temp[10],string_temp_R1[10],string_temp_R2[10];
            if(temp==EOF)break;

            if ((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z'))
            {

                temp=toupper(temp);

                // /entry is in this string
                string_temp [0] = temp;
                string_temp [1] = '\0';

                //plugboard res is in this string
                plug_board_temp [0] = plugboard(temp , ArrPlug);
                plug_board_temp [1] = '\0';
                
                
                temp=plugboard(temp, ArrPlug);
                

                change_mode(string_temp , plug_board_temp);
                

                back = pre_reflector(&RotorsArr[0], temp - 65, RotorsArr[0].ShiftChar);
                //
                string_temp_R1[0] = back+65;

                // first rotor logging
                logging (plug_board_temp , string_temp_R1,"R1");



                for (size_t i = 1; i < 4; i++)
                {

                    back = pre_reflector(&RotorsArr[i], back, RotorsArr[i - 1].ArrRotor[RotorsArr[i-1].Position]);
        
                    string_temp_R2 [0] = back+65;
                    string_temp_R2 [1] = '\0';

                    if( i  == 1){logging(string_temp_R1 , string_temp_R2 ,"R2");string_temp_R1[0] = string_temp_R2[0];}

                    if( i  ==2 ){logging(string_temp_R1 ,string_temp_R2,"R3");  string_temp_R1[0] = string_temp_R2[0];}

                    if( i  == 3){logging(string_temp_R1 ,string_temp_R2,"Ref");string_temp_R1[0] = string_temp_R2[0];}

                }

                for (int i = 2; i > -1; i--)
                {
                    former_output = back;
                    back = post_reflector(&RotorsArr[i], back); 

                    
                    string_temp_R2 [0] = back+65;
                    string_temp_R2 [1] = '\0';

                    if( i == 2 ){logging(string_temp_R1 ,string_temp_R2 ,"R3"); string_temp_R1[0] =string_temp_R2[0];}

                    if( i == 1 ){logging(string_temp_R1 ,string_temp_R2 ,"R2"); string_temp_R1[0] = string_temp_R2[0];}

                    if( i == 0 ){logging(string_temp_R1 ,string_temp_R2 ,"R1"); string_temp_R1[0] = string_temp_R2[0];}
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
                
            
            plug_board_temp[0] = plugboard(back+65 , ArrPlug);
            plug_board_temp[1] = '\0';
            string_temp[0] = back+65;
            string_temp[1] = '\0';
            change_mode(string_temp , plug_board_temp);
            
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
