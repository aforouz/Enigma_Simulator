///////////////////////////////////////////////////////////
//////////// | This part is not completed yet | ////////////
///////////////////////////////////////////////////////////
#include "Main.h"
//included in "config.h"(main header)


const char *stages[10] = {
    "  Input  ", " Plugin1 ", " Rotor 1 ", " Rotor 2 ", " Rotor 3 ", "Reflector", " Rotor 3 ", " Rotor 2 ", " Rotor 1 ", " Plugin2 "
};

void indicate_data_generated(char *data) {
    printf("\x1b[32m");

    for(int i=0;i<10;i++)
    {
        if(i==9)printf("%s\n",stages[i]);
        else printf("%s | ",stages[i]);
    }

    for(int i=0;i<118;i++)printf("-");
    printf("\n");

    for(int i=0;i<10;i++)
    {
        if(i==9)printf("    %c    \n",data[i]);
        else printf("    %c     | ",data[i]);
    }

    printf("\x1b[0m\n\n");
}
