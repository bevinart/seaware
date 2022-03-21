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
        config = placeholder;
    }

    config = remove_char(config, ' ');
    config = remove_comments(config);
    
    // Needs value counter for memory allocation
    newConf.singleValues = (char ***)malloc(sizeof(config)+1);
    newConf.multiValues = (char ****)malloc(sizeof(config)+1);

    for (int i = 0; i < strlen(config); i++) {
        if () {

        }

        // Multi Value
        if (config[i]==delim && config[i+1]=='{') {

        }
        // Single Value
        else if (config[i]==delim) {
            char * pholder = config;
            char * split = strtok(pholder, ":");
            char * firstValue = split;
            split = strtok(NULL, ":");
            char * secondValue = strtok(split, "\n");

            newConf.singleValues[newConf.singleSize] = (char **)malloc(strlen(firstValue)+strlen(secondValue)+1);
            newConf.singleValues[newConf.singleSize][0] = (char*)malloc(strlen(firstValue)+1);
            newConf.singleValues[newConf.singleSize][0] = firstValue;

            newConf.singleValues[newConf.singleSize][1] = (char*)malloc(strlen(secondValue)+1);
            newConf.singleValues[newConf.singleSize][1] = secondValue;

            printf("%s\n", newConf.singleValues[newConf.singleSize][1]);

            newConf.singleSize++;
        }

        // normal char
        else {
            printf("%c", config[i]);
            continue;
        }
        continue;
    }


    return newConf;
}

char * print_config(cfg conf) {
    return "Testing";
}