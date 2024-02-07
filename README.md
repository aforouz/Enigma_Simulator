
# THE ENIGMA
- Description
[![1.jpg](https://i.postimg.cc/8PCWCJjS/1.jpg)](https://postimg.cc/K4d4qYPq)

The Enigma machine is a cipher device developed and used in the early- to mid-20th century to protect commercial, diplomatic, and military communication. It was employed extensively by Nazi Germany during World War II, in all branches of the German military. The Enigma machine was considered so secure that it was used to encipher the most top-secret messages.


The Enigma has an electromechanical rotor mechanism that scrambles the 26 letters of the alphabet. In typical use, one person enters text on the Enigma's keyboard and another person writes down which of the 26 lights above the keyboard illuminated at each key press. If plain text is entered, the illuminated letters are the ciphertext. Entering ciphertext transforms it back into readable plaintext. The rotor mechanism changes the electrical connections between the keys and the lights with each keypress

## More Information 

[The Enigma Cipher Machine](https://en.wikipedia.org/wiki/Enigma_machine)



[![Enigma.jpg](https://i.postimg.cc/DytZK8G5/Enigma.jpg)](https://postimg.cc/Xpk3fNQy)

## Acknowledgements

 - [How does Enigma work(YouTube Video)](https://www.google.com/search?q=how+does+the+enigma+work&client=firefox-b-d&sca_esv=600789614&ei=MfavZZOSN4KLi-gPpu-YuAM&oq=how+does+the+enigma+work&gs_lp=Egxnd3Mtd2l6LXNlcnAiGGhvdyBkb2VzIHRoZSBlbmlnbWEgd29yayoCCAAyBRAAGIAEMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB4yCBAAGBYYHhgPMgYQABgWGB4yBhAAGBYYHjIGEAAYFhgeMgYQABgWGB5IwO8BUOkKWOJWcAJ4AZABAJgBjQSgAZ42qgEKMi0xNS41LjIuMbgBAcgBAPgBAagCCcICChAAGEcY1gQYsAPCAh0QLhjlAhiABBiKBRjqAhi0AhiKAxi3AxjUA9gBAcICIBAAGIAEGIoFGOUCGOUCGOoCGLQCGIoDGLcDGNQD2AEBwgIgEC4YgAQYigUY5QIY5QIY6gIYtAIYigMYtwMY1APYAQHCAgsQLhiABBiKBRiRAsICCxAAGIAEGIoFGJECwgIQEC4YgAQYigUYQxjHARjRA8ICBRAuGIAEwgIKEC4YgAQYigUYQ8ICCBAuGIAEGNQCwgILEAAYgAQYigUYhgPiAwQYACBBiAYBkAYIugYECAEYBw&sclient=gws-wiz-serp)

 - [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher)

 - [Bombe](https://en.wikipedia.org/wiki/Bombe)


## Tech Stack

**Technology used:** The C Programming Language



## Simulation

Each source file contains comments to explain the workflow.
Usage includes different types of both Encryption and Decryption.
for this project the 3-Rotored model was taken as the refrence.
please read the "usage.txt" before installation and use. 
The program can be used in three modes : 

- 1)Single character wich shows the exact workflow in each session.

- 2)An array of characters as input and then another array as output.

- 3)A ".txt" file as input and another one for output



## Usage/Examples
Please read "usage.txt" before installation and use.
This machine has three different types of input/output.
And two different types of configuration.
The machine will recover the latest config.
In the first start you will be asked to setup the machine completely.

- Main driver source code :
```c
#include "config.h"//Header well-documented.


int main(void)
{
    // ########################################## CLI AND MENU
    // Show welcome page and ask username & password
    login();

    // ########################################## MEMORY RESERVATION

    Rotor RotorsArr[4];//Four rotors and one reflector
    char ArrPlug[26];//Plugboard Array

    // ########################################## Setting Configuration

    config(RotorsArr, ArrPlug);//Rotor and plugboard configuration

    check_last_log(RotorsArr);

    while (1)
    {
        int selected_mode = select_mode(); // Select input/output mode

        // ########################################## Main Algorithm
        
        enigma(selected_mode, RotorsArr, ArrPlug);

        save_rotor_posisions(RotorsArr);

        finish();
    }

    return 0;
}
// END OF FILE

```


## Features

- Live previews .
- Cross platform . 
- Real time/exact workflow table. 
- Machine will recover the latest config.
- Morse code .
- Config files .
- Functional Usage (i.e. txt to txt) .
- Interactive Command Line Interface(CLI) .
- Detailed log files . 
- Three different methods of using the machine.
- Capable of modifying the configuration in two different ways.(CLI & .TXT) .
- Encrypted Username and password.
- Well adjusted requests.
- Username and password Verification .
- Username and password check

## Screenshots

![App Screenshot]((https://i.postimg.cc/2SHNnjmz/Screenshot-2024-02-07-202522.png)(https://postimg.cc/21BtDDVJ))


## Authors
We are freshman students at ["Isfahan University of Technology"](https://english.iut.ac.ir/)

[![iut.png](https://i.postimg.cc/fySNHf8s/iut.png)](https://postimg.cc/m14JkCxp)



This is a school project and our group members are :S
- [M.Kazemainy](https://github.com/M-H-K-ir)
- [P.Aminpoor](https://github.com/ParsaAminpour)
- [M.Ebrahimian](https://github.com/m0ebraahim)
- [A.Ahmadi](https://github.com/Wolfe1729)
- [H.Keyghobadi](https://github.com/hsnkei)
- [A.Jafari](https://github.com/AliJafari5383)
- [M.Siamaki](https://github.com/mohammads2005)
## Support

For support, AlirezaAhmadi1729@gmail.com.


## Feedback

If you have any feedback, please reach out to us at AlirezaAhmadi1729@gmail.com


## Related

Here are some related projects :


[RSA](https://en.wikipedia.org/wiki/RSA_(cryptosystem))


## License

[IUT](https://english.iut.ac.ir/)

