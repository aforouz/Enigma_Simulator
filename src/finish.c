#include "config.h"

void finish()
{
    int input=0,menu=1;

    while(1)
    {
        if(input==13)break;
        if(input==80)menu++;
        if(input==72)menu--;
        if(menu>2)menu=1;
        if(menu==0)menu=2;

        system("cls");

        printf("\x1B[33mWhat Do You Want To Do?\n");
        printf("Use Up/Down Key And Press Enter\x1B[0m\n\n");

        if(menu==1)printf("\x1B[32m-> ");else printf("\x1B[0m   ");
        printf("Select Mode And Use Simulator Again\n");

        if(menu==2)printf("\x1B[32m-> ");else printf("\x1B[0m   ");
        printf("Sign out And Exit\n");

        input=getch();
    }

    if(menu==2)
    {
        printf("\x1B[0m");
        printf("\nIf You Want Use Log File Next Time Please Don't Change settings.txt");
        printf("\n\nProgram Exited! Bye:)");
        getch();
        exit(0);
    }
}