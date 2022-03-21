#include "files.h"
#include "converter.h"
#include <string.h>

typedef struct Config {
    char *** singleValues;
    char **** multiValues;
    int singleSize;
    int multiSize;
} cfg;

cfg read_config(char * cfg, char delim);
char * print_config(cfg conf);

cfg add_single_value(char ** value);
cfg add_multi_value(char *** value);