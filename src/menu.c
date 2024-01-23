#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void login();

int main()
{
    login();
    return 0;
}

void login()
{
    system("cls");
    printf("\x1B[31m __        __   _                            _____       _____       _                         ____  _                 _       _             \n");
    printf("\x1B[35m \\ \\      / /__| | ___ ___  _ __ ___   ___  |_   _|__   | ____|_ __ (_) __ _ _ __ ___   __ _  / ___|(_)_ __ ___  _   _| | __ _| |_ ___  _ __ \n");
    printf("\x1B[34m  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\   | |/ _ \\  |  _| | '_ \\| |/ _` | '_ ` _ \\ / _` | \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|\n");
    printf("\x1B[32m   \\ V  V /  __/ | (_| (_) | | | | | |  __/   | | (_) | | |___| | | | | (_| | | | | | | (_| |  ___) | | | | | | | |_| | | (_| | || (_) | |   \n");
    printf("\x1B[33m    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|   |_|\\___/  |_____|_| |_|_|\\__, |_| |_| |_|\\__,_| |____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   \n");
    printf("                                                                       |___/                                                                 \n\n");
    printf("\x1B[36m Ali Forouzandeh Hafshejani   Ali Jafari   Alireza Ahmadi   Mehdi Ebrahimian   Mohammad Hosein Kazemainy   Mohammad Siamaki   Parsa Aminpour\n\n\n\x1B[0m");

    char temp,input[9],password[9]={'1','2','3','4','5','6','7','8','\0'};
    input[8]='\0';
    int i,try=0;
    printf("Please Enter Login Password (8 characters):");

    try_again:

    for(i=0;i<8;i++)
    {
        temp=getch();
        if(temp==27)exit(0);//Esc key
        printf("*");
        input[i]=temp;
    }

    if(strcmp(input,password)==0)
    {
        printf("\nOk Now Simulator Is Ready");
    }
    else
    {
        try++;
        printf("\nPlease Try Again (tries:%d):",try);
        goto try_again;
    }
}