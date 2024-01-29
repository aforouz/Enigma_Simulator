///////////////////////////////////////////////////////////
//////////// | This part is not completed yet | ////////////
///////////////////////////////////////////////////////////
#include"config.h"

FILE *fpt;

void input(int menu_num ,char *s_first,char *s_end){
    if(menu_num == 1){//print output in consol char by char
        for(int i=0; i<SIZE;i++){
          if(s_end[i]=='\0') break;
          printf("%c -> %c \n", s_first[i] , s_end[i]);
        }
    }else if(menu_num == 2){//print output in consol by string
        printf("\n%s",s_end);
    }else if(menu_num == 3){//print output in file char by char
        fpt = fopen("text.txt" , "a+");
        for(int i=0; i<SIZE; i++){
          if(s_end[i] == '\0') break;
          fprintf(fpt , "%c -> %c \n", s_first[i] , s_end[i]);
        }
    }else if(menu_num == 4){//print output in file by string
        fpt = fopen("text.txt" , "a+");
        fputs(s_end , fpt);
    }
}
