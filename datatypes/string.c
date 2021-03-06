#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

string new_string() {
    string newStr;
    newStr.value = malloc(1);
    newStr.value[0] = '\0';
    newStr.add = add_strings;
    newStr.count = count_substr;
    newStr.remove = remove_substr;
    newStr.split = split;
    return newStr;
}

char * add_strings(string str, int argNum, ...) {
    va_list vl;
    int mallocLen = strlen(str.value)+1;
    char * placeHolder = malloc(mallocLen);
    strcpy(placeHolder, str.value);

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

<<<<<<< HEAD
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
=======
char * remove_substr(string str, char * delim) {
    char * newVal = malloc(strlen(str.value)+1);
    int newValPtr = 0;

    for (int i = 0; i < strlen(str.value); i++) {
        char token[strlen(delim)+1];
        memcpy(token, &str.value[i], strlen(delim));
        if (strncmp(token, delim, strlen(delim))==0) {
            i+=strlen(delim)-1;
        }
        else {
            newVal[newValPtr] = str.value[i];
            newValPtr++;
>>>>>>> f27217061551b27972304f8488440a0045be5858
        }
        else {
            i+=strlen(delim)-1;
        }
    }
<<<<<<< HEAD

    ret[retPtr] = '\0';
    return ret;
}

char ** split(char * str, char * delim) {
=======
    return newVal;
}

int count_substr(string str, char * delim) {
    int count = 0;

    for (int i = 0; i < strlen(str.value)-strlen(delim); i++) {
        char token[strlen(delim)];
        memcpy(token, &str.value[i], strlen(delim));
        if (strncmp(token, delim, strlen(delim))==0) {
            count++;
            i+=strlen(delim)-1;
        }
    }

    return count;
}

char * trim(string str) {
    char * newVal = malloc(1);
    int stringStartPoint = 0;
    int stringCopySize = 0;
    for (int i = 0; i < strlen(str.value); i++) {
        if (str.value[i] != ' ') {
            break;
        }
        stringStartPoint = i+1;
    }
    for (int k = 0; str.value[strlen(str.value)-k-1] == ' '; k++) {
        stringCopySize = (strlen(str.value)-k-1)-stringStartPoint;
    }
    newVal = realloc(newVal, stringCopySize+1);
    memcpy(newVal, &str.value[stringStartPoint], stringCopySize);
    newVal[stringCopySize] = '\0';
    return newVal;
}


char ** split(string str, char * delim) {
>>>>>>> f27217061551b27972304f8488440a0045be5858
    char ** splits = malloc(sizeof(char*)+1);
    int splitsPtr = 0;

    char * placeHolder = malloc(strlen(str.value)+1);
    int placeHolderPtr = 0;
<<<<<<< HEAD
    for (int i = 0; i < strlen(str); i++) {
        char token[strlen(delim)+1];
        memcpy(token, &str[i], strlen(delim));

=======
    for (int i = 0; i < (strlen(str.value)); i++) {
        char token[strlen(delim)+1];
        memcpy(token, &str.value[i], strlen(delim));
>>>>>>> f27217061551b27972304f8488440a0045be5858
        if (strncmp(token, delim, strlen(delim))==0) {
            splits = realloc(splits, sizeof(char*)*(splitsPtr+2));
            splits[splitsPtr] = malloc(strlen(placeHolder)+1);
            strcpy(splits[splitsPtr], placeHolder);
            
            splitsPtr++;
            placeHolderPtr = 0;
            i+=strlen(delim)-1;
        }
        else {
            placeHolder[placeHolderPtr] = str.value[i];
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