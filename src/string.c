#include "../string.h"

char * add_strings(int args, ...) {
    va_list vl;
    va_start(vl, args);
    char placeHolder[255*args];

    for (int i = 0; i < args; i++) {
        strcat(placeHolder, va_arg(vl, char*));        
    }
    char * ret = placeHolder;
    return ret;
}

char * remove_char(char * str, char delim) {
    char newStr[strlen(str)+1];
    int ptr = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i]!=delim) {
            newStr[ptr] = str[i];
            ptr++;
        }
    }
    char * answer = newStr;
    return answer;
}


char * remove_substr(char * str, char * delim) {

}

char ** split(char * str, char * delim) {

}
char * h_split(char * str, char * delim) {

}
char * t_split(char * str, char * delim) {

}

// Int to String
char * itos(int num) {
    char str[255];
    sprintf(str, "%d", num);
    char * ret = str;
    return ret;
}
// Long to String
char * ltos(long num) {
    char str[255];
    sprintf(str, "%ld", num);
    char * ret = str;
    return ret;
}
// Float to String
char * ftos(float num) {
    char str[255];
    sprintf(str, "%f", num);
    char * ret = str;
    return ret;
}