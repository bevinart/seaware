#ifndef CWARE_STRING_H

// Combines all strings into one
// 'int args' : # of args
char * add_strings(int args, ...);

char * remove_char(char * str, char delim);
char * remove_substr(char * str, char * delim);


// Splits string into multiple sections
char ** split(char * str, char * delim);
// Returns head of string
char * h_split(char * str, char * delim);
// Returns tail of string
char * t_split(char * str, char * delim);

// Converters
char * itos(int num);
char * ftos(float num);

#define CWARE_STRING_H
#endif