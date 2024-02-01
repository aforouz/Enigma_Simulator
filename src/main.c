//               ,---------------------------,    --------------------
//               |  /---------------------\  |   | Parsa Aminpour     |
//               | |                       | |   | Mohammad Kazemainy |
//               | |     Welcome to        | |   | Alireza Ahmadi     |
//               | |      Enigma           | |   | Mohammad Siamaki   |
//               | |       Machine         | |   | Mohammad Ebrahimian|
//               | |                       | |   | Ali Jafari         |
//               |  \_____________  _ 1402/  |   | Hossein Keyghobadi |
//               |___________IUT_____________|    --------------------
//             ,---\_____     []     _______/------,
//           /         /______________\           /|
//         /___________________________________ /  | ___
//         |          Math Department          |   |    )
//         |  _ _ _                 [-------]  |   |   (
//         |  o o o                 [-------]  |  /    _)_
//         |__________________________________ |/     /  /
//     /-------------------------------------/|      ( )/
//   /U/S/E/-/E/N/I/G/M/A/-/M/A/C/H/I/N/E/-/ /
//  /A/N/D/-/S/A/Y/-/H/I/-/H/I/T/L/E/R/-/-/ /







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
