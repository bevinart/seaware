#include "../converter.h"

char  * remove_char(char * str, char delim) {
    char newStr[strlen(str)+1];
    int ptr = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i]!=delim) {
            newStr[ptr] = str[i];
            ptr++;
        }
    }
    newStr[ptr] = '\0';
    return newStr;
}