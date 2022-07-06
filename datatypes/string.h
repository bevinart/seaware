#ifndef CWARE_STRING_H

struct SEAWARE_STRING{
    char * value;
    char * (*add)(struct SEAWARE_STRING str, int args, ...);
    int (*count)(struct SEAWARE_STRING str, char * delim);
    char * (*remove)(struct SEAWARE_STRING str, char * delim);
    char ** (*split)(struct SEAWARE_STRING str, char * delim);
    char * (*trim)(struct SEAWARE_STRING str);
};
typedef struct SEAWARE_STRING string;

string new_string();

// Combines all strings into one
// 'int args' : # of args
char * add_strings(string str, int args, ...);

int count_substr(string str, char * delim);
char * remove_substr(string str, char * delim);

char * trim(string str);

// Splits string into multiple sections
char ** split(string str, char * delim);

// Converters
char * itos(int num);
char * ftos(float num);

#define CWARE_STRING_H
#endif