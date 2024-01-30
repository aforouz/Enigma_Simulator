#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void read_settings(int rotor_number,int *r1n,int *r1p,int *r2n,int *r2p,int *r3n,int *r3p,char *plugs)
{
    FILE *sets;

    sets=fopen("settings.txt","r");
    if(sets==NULL)
    {
        printf("settings.txt Not Found!!!");
        exit(0);
    }

    if(fscanf(sets,"Rotor1:%d,%d Rotor2:%d,%d Rotor3:%d,%d",r1n,r1p,r2n,r2p,r3n,r3p)!=6)
    {
        printf("settings.txt Not Correct!!!");
        exit(0);
    }

    if(*r1n<1 || *r1n>rotor_number || *r2n<1 || *r2n>rotor_number || *r3n<1 || *r3n>rotor_number)
    {
        printf("settings.txt : Rotor Number 1 to %d",rotor_number);
        exit(0);
    }

    if(*r1p<0 || *r1p>25 || *r2p<0 || *r2p>25 || *r3p<0 || *r3p>25)
    {
        printf("settings.txt : Rotor Position 0 to 25");
        exit(0);
    }

    for(char i='A';i<='Z';i++)plugs[i-'A']=i;

    char temp,line[5],a,b;
    int i=0;

    while(fgetc(sets)!='*');
    fgetc(sets);//for \n

    while(1)
    {
        temp=fgetc(sets);

        if(temp=='*')break;

        if(temp=='\n')
        {
            if(sscanf(line,"(%c:%c)",&a,&b)!=2 || !isupper(a) || !isupper(b))
            {
                printf("settings.txt Not Correct!!!");
                exit(0);
            }
            plugs[a-'A']=b;
            plugs[b-'A']=a;
            i=0;
        }
        else
        {
            line[i++]=temp;
        }
    }

    fclose(sets);
}

int main()
{
    int r1n,r1p,r2n,r2p,r3n,r3p;
    char plugs[26];
    read_settings(5,&r1n,&r1p,&r2n,&r2p,&r3n,&r3p,plugs);
    printf("%d %d,%d %d,%d %d\n",r1n,r1p,r2n,r2p,r3n,r3p);
    for(int i=0;i<26;i++)printf("%c ",plugs[i]);
    return 0;
}