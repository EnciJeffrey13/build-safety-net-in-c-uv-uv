// #ifndef SOUNDEX_H
// #define SOUNDEX_H

// #include "Soundex.h"
// #include <ctype.h>
// #include <string.h>

// char getSoundexCode(char c) {
//     c = toupper(c);
//     switch (c) {
//         case 'B': case 'F': case 'P': case 'V': return '1';
//         case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
//         case 'D': case 'T': return '3';
//         case 'L': return '4';
//         case 'M': case 'N': return '5';
//         case 'R': return '6';
//         default: return '0'; // For A, E, I, O, U, H, W, Y
//     }
// }

// void generateSoundex(const char *name, char *soundex) {
//     int len = strlen(name);
//     soundex[0] = toupper(name[0]);
//     int sIndex = 1;

//     for (int i = 1; i < len && sIndex < 4; i++) {
//         char code = getSoundexCode(name[i]);
//         if (code != '0' && code != soundex[sIndex - 1]) {
//             soundex[sIndex++] = code;
//         }
//     }

//     while (sIndex < 4) {
//         soundex[sIndex++] = '0';
//     }

//     soundex[4] = '\0';
// }

// #endif // SOUNDEX_H

#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>
void generateSoundex(const char *name, char *soundex){
    char mappings[] = "01230120022455012623010202";
    memset(soundex, '0', 4);
    soundex[0] = toupper(name[0]);
    int sIndex = 1, i = 1;
    while(++i < strlen(name) && sIndex < 4){
        char c = toupper(name[i]) - 65;
        if (mappings[c] != '0' && mappings[c] != soundex[sIndex - 1]) 
            soundex[sIndex++] = mappings[c];
    }
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
