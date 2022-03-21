#include "../converter.h"

char * remove_char(char * str, char delim) {
    char * newStr = (char*)malloc(strlen(str)+1);
    int ptr = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i]!=delim) {
            newStr[ptr] = str[i];
            ptr++;
        }
    }
    return newStr;
}