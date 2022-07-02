#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char * add_strings(int argNum, ...) {
    va_list vl;
    int mallocLen = 1;
    char * placeHolder = malloc(mallocLen);
    *placeHolder = '\0';

    va_start(vl, argNum);

    for (int i = 0; i < argNum; i++) {
        char * arg = va_arg(vl, char*);
        mallocLen += strlen(arg);
        placeHolder = realloc(placeHolder, mallocLen);
        strcat(placeHolder, arg);
    }
    
    va_end(vl);
    return placeHolder;
}

int count_substr(char * str, char * delim) {
    int ret = 0;
    
    for (int i = 0; i < strlen(str)-strlen(delim); i++) {
        char token[strlen(delim)];
        memcpy(token, &str[i], strlen(delim));
        if (strncmp(token, delim, strlen(delim)) == 0) {
            ret++;
            i+=strlen(delim)-1;
        }
    }

    return ret;
}

char * remove_substr(char * str, char * delim) {
    char * ret = malloc(1);
    int retPtr = 0;

    for (int i = 0; i < strlen(str); i++) {
        char token[strlen(delim)];
        memcpy(token, &str[i], strlen(delim));
        if (strncmp(token, delim, strlen(delim)) != 0) {
            ret = realloc(ret, retPtr+2);
            ret[retPtr] = str[i];
            retPtr++;
        }
        else {
            i+=strlen(delim)-1;
        }
    }

    ret[retPtr] = '\0';
    return ret;
}

char ** split(char * str, char * delim) {
    char ** splits = malloc(sizeof(char*)+1);
    int splitsPtr = 0;

    char * placeHolder = malloc(strlen(str)+1);
    int placeHolderPtr = 0;
    for (int i = 0; i < strlen(str); i++) {
        char token[strlen(delim)+1];
        memcpy(token, &str[i], strlen(delim));

        if (strncmp(token, delim, strlen(delim))==0) {
            splits = realloc(splits, sizeof(char*)*(splitsPtr+2));
            splits[splitsPtr] = malloc(strlen(placeHolder)+1);
            strcpy(splits[splitsPtr], placeHolder);
            
            splitsPtr++;
            placeHolderPtr = 0;
            i+=strlen(delim)-1;
        }
        else {
            placeHolder[placeHolderPtr] = str[i];
            placeHolderPtr++;
        }
    }

    placeHolder[placeHolderPtr] = '\0';
    splits[splitsPtr] = malloc(strlen(placeHolder)+1);
    strcpy(splits[splitsPtr], placeHolder);

    free(placeHolder);

    return splits;
}

// Int to String
char * itos(int num) {
    char * str = malloc(255);
    sprintf(str, "%d", num);
    str = realloc(str, strlen(str)+1);
    return str;
}
// Float to String
char * ftos(float num) {
    char * str = malloc(255);
    sprintf(str, "%f", num);
    str = realloc(str, strlen(str)+1);
    return str;
}