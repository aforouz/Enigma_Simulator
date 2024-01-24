#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void login();
void getPassword(char *password)
{
    strcpy(password,"12345678");
}

int main()
{
    login();
    return 0;
}

void login()
{
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
    printf("                                     Ali Forouzandeh Hafshejani   Ali Jafari   Alireza Ahmadi   Mehdi Ebrahimian\n");
    printf("                                            Mohammad Hosein Kazemainy   Mohammad Siamaki   Parsa Aminpour\n");
    printf("                                   *******************************************************************************\n\n\n\x1B[0m");

    char temp,input[9]={},password[9];
    int i,try=0;

    getPassword(password);

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
        printf("\nPlease Try Again (Try no.%d):",try);
        goto try_again;
    }
}