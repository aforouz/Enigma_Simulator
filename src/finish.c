#include "Main.h"

void finish()
{
    int _input=0,_menu=1;

    while(1)
    {
        if(_input==13)break;
        if(_input==80)_menu++;
        if(_input==72)_menu--;
        if(_menu>2)_menu=1;
        if(_menu==0)_menu=2;

        system("cls");

        printf("\x1B[33mWhat Do You Want To Do?\n");
        printf("Use Up/Down Key And Press Enter\x1B[0m\n\n");

        if(_menu==1)printf("\x1B[32m-> ");else printf("\x1B[0m   ");
        printf("Select Mode And Use Simulator Again\n");

        if(_menu==2)printf("\x1B[32m-> ");else printf("\x1B[0m   ");
        printf("Sign out And Exit\n");

        _input=getch();
    }

    if(_menu==2)
    {
        printf("\x1B[0m");
        printf("\nIf You Want Use Log File Next Time Please Don't Change settings.txt");
        printf("\n\nProgram Exited! Bye:)");
        getch();
        exit(0);
    }
}