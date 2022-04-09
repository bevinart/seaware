#include "../config.h"

void update_config(char * filePath, struct Config cfg) {
    remove(filePath);
    for (int i = 0; i < cfg.valuesSize; i++) {
        append_file(filePath, "{\n");
        for (int j = 0; j < 4; j++) {
            append_file(filePath, cfg.values[i][j][0]);
            append_file(filePath, ":");
            append_file(filePath, cfg.values[i][j][1]);
            append_file(filePath, "\n");
        }
        append_file(filePath, "}\n");
    }
}

struct Config read_config(struct Config newCfg, char * cfg) {
    int configIsMalloc = 0;

    char * config;
    if (file_exists(cfg)) {
        config = read_file(cfg);
        configIsMalloc=1;
    }
    else {
        config = cfg;
    }
    if (newCfg.valuesSize == 0) {
        newCfg.values = malloc(sizeof(char****)*255);
        *newCfg.values = '\0';
    }
    int valuesPtr = 0;
    while(config) {
        char * nextLine = strchr(config, '\n');
        if (nextLine) *nextLine = '\0';
        if (config[0] == '{') {
            newCfg.values[newCfg.valuesSize] = malloc(sizeof(char***)*255);
            *newCfg.values[newCfg.valuesSize] = '\0';
        }
        else if (strstr(config, "}")) {
            newCfg.valuesSize++;
            valuesPtr=0;
        }
        else if (strstr(config, ":")) {
            newCfg.values[newCfg.valuesSize][valuesPtr] = malloc(sizeof(char**)*255);
            *newCfg.values[newCfg.valuesSize][valuesPtr] = '\0';

            char * split = strtok(config, ":");
            newCfg.values[newCfg.valuesSize][valuesPtr][0] = malloc(strlen(split)*sizeof(char*));
            *newCfg.values[newCfg.valuesSize][valuesPtr][0] = '\0';
            strcat(newCfg.values[newCfg.valuesSize][valuesPtr][0], split);
            printf("%s", newCfg.values[newCfg.valuesSize][valuesPtr][0]);

            split = strtok(NULL, ":");
            newCfg.values[newCfg.valuesSize][valuesPtr][1] = malloc(strlen(split)*sizeof(char*));
            *newCfg.values[newCfg.valuesSize][valuesPtr][1] = '\0';
            strcat(newCfg.values[newCfg.valuesSize][valuesPtr][1], split);
            valuesPtr++;
        }

        if (nextLine) *nextLine = '\n';
        config = nextLine ? (nextLine+1) : NULL;
    }

    (configIsMalloc==1) ? free(config) : NULL;
    return newCfg;
}
