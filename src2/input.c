///////////////////////////////////////////////////////////
//////////// | This part is not completed yet | ////////////
///////////////////////////////////////////////////////////
#include"config.h"



//returns a string from a file
char *input(/*int menu_num*/)
{
    // copy this text on menu: printf("press * at the end of your message \n" );
    char *s;
    s = (char*)calloc(99999999 , sizeof(char));
    // if(menu_num == 1){//get input in consol char by char
      // for(int i=0;;i++){
          // char now;
          // scanf("%c",&now);
          // if(now==42){
            // s[i]='\0';
            // break;
          // }
          // s[i]=now;
      // }
    // }else if(menu_num == 2){//get input in consol by string
        // scanf("%s",s);
    // }else if(menu_num == 3){//get input in file


        fpt = fopen("text.txt" , "a+");//file opened

        char tmp;

        for(int i=0; ; i++)
        {
          fscanf(fpt , "%c%c" , &s[i] , &tmp);

          if(s[i]<65 || s[i]>122)
          {
              if(s[i] == 42)
              {
                 s[i] = '\0';
                 break;
              }
              i--;
          }
        }
    }
    for(int i=0;i<SIZE;i++){//to upper
      if(s[i]>=97&&s[i]<=122)s[i]-=32;

    }
    return s;
}
