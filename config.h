#include "files.h"
#include "converter.h"
#include <string.h>

// MAKE SURE ALL COMMENTS IN CONFIG ARE EITHER
//  a. SPACED FROM THE VALUE
//  b. ON A NEW LINE

typedef struct Config {
    /* Single Values works as follows
         Arch: x86_64
         Arch, singleValues[0][0]
         x86_64, singleValues[0][1]

    */
    char *** singleValues;

    /* There are 2 ways this works
        a. Grabs a set of strings, such as grabbing Repo URLS
        b. Can grab multiple single values and put them under one name

        Example: Single Values
        CFG:
            Specs: {
                Arch: x86_64
            }
        GETTING VALUES:
            Specs, multiValues[0][0]
            Arch, multiValues[0][0][0]
            x86_64, multiValues[0][0][1]


        Example: Repo URLS
        CFG:
            Repos: { URL1, URL2 }
        GETTING VALUES:
            Repos, multiValues[0][0]
            URL1, multiValues[0][0][0]
            URL2, multiValues[0][1][0]
    Due to the fact that they don't need an identifier and only provide one string, 
    We have to make the jump in the *** array
    */    
    char **** multiValues;

    // Acts as a ptr for accessing both values
    int singleSize;
    int multiSize;
} cfg;

cfg read_config(char * cfg, char delim);

int get_sv_size(char * cfg);
int get_mv_size(char * cfg);

char * remove_comments(char * cfg);
char * print_config(cfg conf);