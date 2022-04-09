#ifndef CONFIG_H
#define CONFIG_H

#include <string.h>
#include <stdlib.h>
#include "files.h"

/*
	CONFIG SETUP

{
ID:001
TITLE:SOMETHING
}
{
ID:002
TITLE:ELSE
}

*/


struct Config {
    char **** values;
    int valuesSize;
};

struct Config read_config(struct Config newCfg, char * cfg);
struct Config add_to_config(struct Config dest, char * src);
struct Config remove_from_config(struct Config cfg, int index);

void update_config(char * filePath, struct Config cfg);

#endif
