#include "Main.h"

void menu()
{
    // ########################################## CLI AND MENU
    // Show welcome page and ask username & password
    login();

    // ########################################## MEMORY RESERVATION

    Rotor RotorsArr[4];//Four rotors and one reflector
    char ArrPlug[26];//Plugboard Array

    // ########################################## Setting Configuration

    config(RotorsArr, ArrPlug);//Rotor and plugboard configuration

    check_last_log(RotorsArr);

    while (1)
    {
        int selected_mode = select_mode(); // Select input/output mode

        // ########################################## Main Algorithm
        
        enigma(selected_mode, RotorsArr, ArrPlug);

        save_rotor_posisions(RotorsArr);

        finish();
    }
}