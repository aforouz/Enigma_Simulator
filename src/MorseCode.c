//    """Talk is cheap, show me the code!!!"""
// 
//    -Linus Torvalds


//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=+
//                                           MORSE_CODE
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=+
// @title  : Morse_Code_Function   USAGE EXAMPLE INCLUDED!!
// @author : Ahmadi  
// 
// @notice : This source-code can be toggled on or off
//           (one variant of operation works with txt files
//           witch will be added asap).
//           this source can be used with a string or 
//           a single char allowing multiple choices
// 
// @dev    : This source depends upon the main config(header) file 
// @custom : function prototypes are in "Config.h".
//           Improvments are welcomed !!!


//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=+
//                                          DECLARATIONS
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=+

//    #FIXME: Header files

//   ---> #include "config.c" <---    This file will be modified ASAP

//this section will be modified later


#include "config.h"



//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=+
//                                            FUNCTIONS
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=+
//         LIST:
//       1. morse_to_index
//       2. char_to_morse
//       3. morse_to_char



//+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+
//       #1         morse_to_index
//+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+
//    NOTE1 :: You will not use this function anywhere
//             Therefore no explanation needed
// 
//             It is written for the sake of clean code
//             By procces the morse code
//             It is actually used by the morse_to_char
               

int morse_to_index(const char* str)
{
    unsigned char sum = 0, bit;

    for (bit = 1; bit; bit <<= 1) {
        switch (*str++) {
        case 0:
            return sum | bit;
        default:
            return 0;
        case '-':
            sum |= bit;
            
        case '.':
            break;
        }
    }

    return 0;
}



//+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+
//      #2           char_to_morse
//+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+
// 
//The function takes """ONE ARGUMENT""" at a time 
//and returns the morse code... the return is a value
// wich consists of both dots and lines   example: --> "A" : .-
//  
// NOTE1 ::   Always allocate larger memory for return values
// 
// NOTE2 ::  "IMPORTANT"   for strings it MUST BE USED WITHTIN A LOOP
//                        with each character passed to it once at a time
// 
// NOTE3 ::  Looking at the header file where the functions and morse definitions are
//           located might be useful


// IMPORTANT    EXAMPLE OF USE:
//------------------------------
//  int main(void)
//  {
//     char i = char_to_morse('A');
//     puts(i); 
//  }
      //OUTPUT IN KONSOLE :.-




const char* char_to_morse(char c)
{
    if (islower(c))
        c += ('A' - 'a');

    return CHAR_TO_MORSE[(int)c];//defiend in the header file 
}





//+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+
//        #3         morse_to_char
//+=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+=+=+=+=++=+=+=+
// 
// like the one above but reverse ; it takes the morse code and
// returns the character 
// 


//  IMPORTANT   EXMAPLE OF USE

//  int main(void)
//  {
//    char i = morse_to_char('.-');
//    puts(i);
//  }
//  OUTPUT IN KONSOLE : --> A




const char* morse_to_char(const char* str)
{
    return MORSE_TO_CHAR[morse_to_index(str)];
}


//END OF FILE
