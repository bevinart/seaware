#include "../config.h"

cfg read_config(char * cfgFile, char delim) {
    cfg newConf;
    newConf.singleSize = 0;
    newConf.multiSize = 0;

    char * config;
    if (file_exists(cfgFile)==false) {
        config = (char*)malloc(strlen(cfgFile)+1);
        config = cfgFile;
    }
    else {
        char * placeholder = read_file(cfgFile);
        config = (char*)malloc(strlen(placeholder)+1);
        config = cfgFile;
    }
    for (int i = 0; i < strlen(config); i++) {
       
    }


    return newConf;
}

char * print_config(cfg conf) {
    return "Testing";
}