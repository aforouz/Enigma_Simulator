// ###############################################
//                DRIVER_CODE
// ###############################################

// ############################################### DECLARATIONS

#include "config.h"

int main(void)
{
    // ##################CLI AND MENU
    // Show welcome page and ask password
    login();

    // 
    Rotor RotorsArr[4];
    char ArrPlug[26];

    // 
    config(RotorsArr, ArrPlug);

    // Select input/output mode
    int selected_mode = select_mode();

    enigma(selected_mode, RotorsArr, ArrPlug);

    return 0;
}
// END OF FILE
