#include "config.h"

void login()
{
    try_again:

    char input=0,user[101],pass[101];
    int i,menu=1;

    while(1)
    {
        if(input==27)//Esc key
        {
            printf("\n\nProgram Exited! Bye:)");
            exit(0);
        }
        if(input==13)break;
        if(input==80)menu++;
        if(input==72)menu--;
        if(menu>2)menu=1;
        if(menu==0)menu=2;

        system("cls");
        printf("\x1B[0m\x1B[31m       ***          \x1B[0m\x1B[47m                                                                                                            \x1B[0m \x1B[31m       ***          \x1B[0m\n");
        printf("\x1B[0m\x1B[31m     ****    **     \x1B[0m\x1B[47m  \x1B[40m _____ _            _____       _                         ____  _                 _       _             \x1B[47m  \x1B[0m \x1B[31m     ****    **     \x1B[0m\n");
        printf("\x1B[0m\x1B[31m     ****  ******   \x1B[0m\x1B[47m  \x1B[40m|_   _| |__   ___  | ____|_ __ (_) __ _ _ __ ___   __ _  / ___|(_)_ __ ___  _   _| | __ _| |_ ___  _ __ \x1B[47m  \x1B[0m \x1B[31m     ****  ******   \x1B[0m\n");
        printf("\x1B[0m\x1B[31m**     *****   **** \x1B[0m\x1B[47m  \x1B[41m  | | | '_ \\ / _ \\ |  _| | '_ \\| |/ _` | '_ ` _ \\ / _` | \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|\x1B[47m  \x1B[0m \x1B[31m**     *****   **** \x1B[0m\n");
        printf("\x1B[0m\x1B[31m****   *****     ** \x1B[0m\x1B[47m  \x1B[41m  | | | | | |  __/ | |___| | | | | (_| | | | | | | (_| |  ___) | | | | | | | |_| | | (_| | || (_) | |   \x1B[47m  \x1B[0m \x1B[31m****   *****     ** \x1B[0m\n");
        printf("\x1B[0m\x1B[31m  ******  ****      \x1B[0m\x1B[47m  \x1B[43m  |_| |_| |_|\\___| |_____|_| |_|_|\\__, |_| |_| |_|\\__,_| |____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   \x1B[47m  \x1B[0m \x1B[31m  ******  ****      \x1B[0m\n");
        printf("\x1B[0m\x1B[31m    **    ****      \x1B[0m\x1B[47m  \x1B[43m                                  |___/                                                                 \x1B[47m  \x1B[0m \x1B[31m    **    ****      \x1B[0m\n");
        printf("\x1B[0m\x1B[31m         ***        \x1B[0m\x1B[47m                                                                                                            \x1B[0m \x1B[31m         ***        \x1B[0m\n\n\n\x1B[0m");
        printf("\x1B[36m                                   *******************************************************************************\n");
        printf("                                                   Ali Jafari   Alireza Ahmadi   Mehdi Ebrahimian\n");
        printf("                                            Mohammad Hosein Kazemainy   Mohammad Siamaki   Parsa Aminpour\n");
        printf("                                   *******************************************************************************\n\n\n\x1B[0m");


        printf("\x1B[33mUse Up/Down Key And Press Enter Or Esc\x1B[0m\n\n");

        if(menu==1)printf("\x1B[32m-> ");else printf("\x1B[0m   ");
        printf("Sign in\n");

        if(menu==2)printf("\x1B[32m-> ");else printf("\x1B[0m   ");
        printf("Sign up\n");

        input=getch();
    }

    printf("\nUser Name (max:100ch):");
    gets(user);
    printf("Password (max:100ch):");

    for(i=0;i<100;i++)
    {
        input=getch();
        if(input==13)//Enter key
        {
            pass[++i]='\0';
            break;
        }
        if(input==27)//Esc key
        {
            printf("\n\nProgram Exited! Bye:)");
            exit(0);
        }
        printf("*");
        pass[i]=input;
    }

    if(menu==1 && signin(user,pass)==0)
    {
        printf("Press Any Key To Try Again");
        getch();
        goto try_again;
    }

    if(menu==2)
    {
        signup(user,pass);
        printf("Press Any Key To Sign in");
        getch();
        goto try_again;
    }
}