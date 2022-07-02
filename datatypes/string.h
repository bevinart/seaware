#ifndef CWARE_STRING_H

// Combines all strings into one
// 'int args' : # of args
char * add_strings(int args, ...);

// Seg fault with counting
int count_substr(char * str, char * delim);

char * remove_substr(char * str, char * delim);

// Splits string into multiple sections
char ** split(char * str, char * delim);

// Converters
char * itos(int num);
char * ftos(float num);

#define CWARE_STRING_H
#endif