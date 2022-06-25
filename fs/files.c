#include "files.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


char * read_file(char * filePath) {
    FILE *file;
    file = fopen(filePath, "r");
    char c;
    char * output = malloc(sizeof(char) * get_file_size(filePath));
    int outputPtr = 0;

    while((c = getc(file)) != EOF) {
        output[outputPtr] = c;
        outputPtr++;
    }

    fclose(file);

    output[outputPtr] = '\0';
    return output;
}
int get_file_size(char * filePath) {
    FILE *file;
    file = fopen(filePath, "r");
    int size = 0;
    char c;
    while( (c = getc(file)) != EOF) {
        size++;
    }

    fclose(file);
    return size;
}

void create_file(char * filePath) {
    FILE *file;
    file = fopen(filePath, "w");
    fclose(file);
}
void append_file(char * filePath, char * content) {
    FILE *file;
    file = fopen(filePath, "a");
    fputs(content, file);
    fclose(file);
}

bool file_exists(char * filePath) {
    FILE *file;
    if (( file = fopen(filePath, "r") )) {
        fclose(file);
        return true;
    }
    return false;
}