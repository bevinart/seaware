#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    If using printf(), DO NOT USE %s! It won't print out the value, instead, just call the function as the first argument
*/

char * remove_char(char * str, char delim);

#endif