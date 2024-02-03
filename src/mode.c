#include "Main.h"

int select_mode()
{
    int input = 0, menu = 1;

    while (1) // get Mode
    {
        if (input == 27) // Esc key
        {
            printf("\n\nProgram Exited! Bye:)");
            getch();
            exit(0);
        }
        if (input == 13)
            break;
        if (input == 80)
            menu++;
        if (input == 72)
            menu--;
        if (menu > 3)
            menu = 1;
        if (menu == 0)
            menu = 3;

        system("cls");

        printf("\x1B[33mNow Simulator Is Ready Please Select Mode\n");
        printf("Use Up/Down Key And Press Enter Or Esc\x1B[0m\n\n");

        if (menu == 1)
            printf("\x1B[32m-> ");
        else
            printf("\x1B[0m   ");
        printf("Character Mode: Input/Output Characters Here (With Enigma Machine Trace Table)\n");

        if (menu == 2)
            printf("\x1B[32m-> ");
        else
            printf("\x1B[0m   ");
        printf("String Mode: Input/Output Strings Here\n");

        if (menu == 3)
            printf("\x1B[32m-> ");
        else
            printf("\x1B[0m   ");
        printf("File Mode: Input/Output Strings From/To File\n");

        input = getch();
    }

    printf("\x1B[0m");

    return menu;
}