///////////////////////////////////////////////////////////
//////////// | This part is not completed yet | ////////////
///////////////////////////////////////////////////////////
#include "config.h"
//included in "config.h"(main header)


const char *stages[10] = {
    "Input", "Plugin", "Rotor1", "Rotor2", "Rotor3", "Reflector", "Rotor3", "Rotor2", "Rotor1", "Plugin"
};

void splitter() {
    printf(" -> ");
    // fflush(stdin);
}

void seperate_vertical_line() {
    printf("| ");
}

void seperate_horizontal_line() {
    int cnt = 0;
    while(cnt <= 105) {
        printf("-");
        cnt ++;
    } printf("\n");
}

void title_of_the_output() {
    seperate_vertical_line();
    for (int i = 0; i < 10; i++) {
        printf("%7s ", stages[i]);
        i == 9 ? printf("\n") : seperate_vertical_line();
    }
    seperate_horizontal_line();
}


bool title_generated = false;
bool last_encryption_generated = false; // indicate ex-generated data
// print in array data input format, this function will use among the Enigma algorithm codes
void indicate_data_generated(char *data) {
    if (title_generated) {
        seperate_vertical_line();

        for (int i = 0; i < 10; i++) {
            printf("\x1b[32m %6c ", data[i]);
            i == 9 ? printf("\n") : seperate_vertical_line();
        }

        seperate_horizontal_line();
    } else {
        title_of_the_output();
        title_generated = true;

        indicate_data_generated(data);
    }
}


// Sample input
#define SIZE_STR 101
int main() {
    char input_data[SIZE_STR];
    gets(input_data);

    indicate_data_generated(input_data);

}

