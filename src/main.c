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
        case char_mode
        break;

        case str_mode
        break;

        case file_mode
        break;
    }

    //#################INPUT_OUTPUT
    // uwu

    //#################LOGGING
    // uwu



    //#################CONFIG

if(log ==NULL || /*The user wanted to change smth in rotors or plugs*/)://if the log was empty
//first we have to define the rotors we want to work with
{
    printf("LOG file not found\n");
    Rotor RotorsArr[4] = rotorinit();//reflector is defined in config.c
    
    //log area start
    // uwu
    //log area end



    //input area start
    //uwu
    //input area end

    for (int j = 0; j < n; j++)
    {
        
        back = pre_reflector(&RotorsArr[0], plugboard(c[i], ArrPlug) - 65, 'a');
        // printf("%c\n", c[i]);
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
        return(plugboard(back + 65, ArrPlug));
    }

    // output area start
    //uwu
    //output area end


    //logging area start
    //uwu
    //logging area end

    //cli area start
    //uwu
    //cli area end
    return 0;

}//END OF FILE


    

    

















}
