#include "Main.h"

void _read_log(Rotor *RotorsArr,int r1,int r2,int r3)
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

        printf("\x1B[33mLast Log File Exists Do You Want Continue From Log?\n");
        printf("Use Up/Down Key And Press Enter\x1B[0m\n\n");

        if(menu==1)printf("\x1B[32m-> ");else printf("\x1B[0m   ");
        printf("YES\n");

        if(menu==2)printf("\x1B[32m-> ");else printf("\x1B[0m   ");
        printf("NO\n");

        input=getch();
    }

    printf("\x1B[0m");

    if(menu==1)
    {
        RotorsArr[0].Position=r1;
        RotorsArr[1].Position=r2;
        RotorsArr[2].Position=r3;
    }
}

void check_last_log(Rotor *RotorsArr)
{
    FILE *logs;
    int r1,r2,r3;

    logs = fopen("./machine_files/machine_logs.log", "r");
    if (logs == NULL)
    {
        fclose(logs);
        return;
    }

    while(fgetc(logs)!=EOF);
    fseek(logs,-16, SEEK_END);

    if(fscanf(logs,"Rotors:(%d,%d,%d)",&r1,&r2,&r3)==3)
    {
        _read_log(RotorsArr,r1,r2,r3);
    }

    fclose(logs);
}

void save_rotor_posisions(Rotor *RotorsArr)
{
    char temp[20];
    sprintf(temp,"Rotors:(%d,%d,%d)\n",RotorsArr[0].Position,RotorsArr[1].Position,RotorsArr[2].Position);
    _writeLog(temp);
}