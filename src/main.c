//               ,---------------------------,    --------------------
//               |  /---------------------\  |   | Parsa Aminpour     |   2024_University of Technology in Isfahan.
//               | |                       | |   | Mohammad Kazemainy |    Departement of Mathematical Sciences.
//               | |     Welcome to        | |   | Alireza Ahmadi     |    
//               | |      The Enigma       | |   | Mohammad Siamaki   |    Open-Source. Any kind of usage permitted... .
//               | |       Machine         | |   | Mahdi Ebrahimian   |
//               | |                  2024 | |   | Ali Jafari         |
//               |  \_____________  _ 1402/  |   | Hossein Keyghobadi |
//               |___________IUT_____________|    --------------------
//             ,---\_____     []     _______/------,
//           /         /______________\           /|
//         /___________________________________ /  | ___
//         |                                   |   |    )
//         |  _ _ _                 [-------]  |   |   (
//         |  o o o                 [-------]  |  /    _)_             THE QUIETER YOU BECOME , THE MORE YOU ARE ABLE TO HEAR.... .
//         |__________________________________ |/     /  /             ------------------------------------------------------------
//     /-------------------------------------/|      ( )/                   -- KALI LINUX   - RUMI
//   /U/S/E/-/E/N/I/G/M/A/-/M/A/C/H/I/N/E/-/ /                                
//  /A/N/D/-/S/A/Y/-/H/A/I/L/-/H/I/T/L/E/R/

                                                                                  


// ###################################################################
//                           DRIVER_CODE
// ###################################################################
// @note: This part calls all of the internal functions and runs the machine.

// ############################################### DECLARATIONS

#include "config.h"//Header well-documented.


int main(void)
{
    // ########################################## CLI AND MENU
    // Show welcome page and ask username & password
    login();

    // ########################################## MEMORY RESERVATION

    Rotor RotorsArr[4];//Four rotors and one reflector
    char ArrPlug[26];//Plugboard Array

    // ########################################## Setting Configuration

    config(RotorsArr, ArrPlug);//Rotor and plugboard configuration 
  
    int selected_mode = select_mode(); // Select input/output mode

    // ########################################## Main Algorithm
    
    enigma(selected_mode, RotorsArr, ArrPlug);

    return 0;
}
// END OF FILE
