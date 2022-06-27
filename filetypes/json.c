#include "json.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_LINE_SIZE 255

char * removeSpacing(char * code);

// Global Functions

// Creates and allocates JSON variable
struct JSON * json_init() {
    struct JSON * jsonStruct = malloc(sizeof(struct JSON)+1);
    jsonStruct->nextField = malloc(sizeof(struct JSON *)+1);
    jsonStruct->property = NULL;
    jsonStruct->values = NULL;
    jsonStruct->prevField = NULL;
    jsonStruct->valuesSize = 0;
    jsonStruct->nextFieldSize = 0;

    return jsonStruct;
}

// I/O Functions

// Reads and interprets JSON file
struct JSON * read_json(struct JSON * json, char * filePath) {
    // Local loop variables
    FILE * jsonFile = fopen(filePath, "r");
    char line[MAX_LINE_SIZE];

    while(fgets(line, sizeof(line), jsonFile)) {
        json = interpret_json(json, line);
    }

    fclose(jsonFile);

    return json;
}

// JSON Interpreter
struct JSON * interpret_json(struct JSON * json, char * jsonCode) {
    // Local interpreter variables
    char * newJsonCode = removeSpacing(jsonCode);

    // For every character in JSON...
    for (int i = 0; i < strlen(newJsonCode); i++) {
        // printf("%c", newJsonCode[i]);

        // The interpreter .. .... .. 
        switch (jsonCode[i]) {

            // :
            case DELIM: {

                // Gets property name

                // Sets property name

                break;                
            }

            // ,
            case SEPARATOR: {
                
                break;
            }

            // {
            case OPEN_BLOCK_DELIM: {
                break;
            }

            // }
            case CLOSE_BLOCK_DELIM: {
                // if (json->prevField != NULL) {
                //     json = json->prevField;
                // }
                break;
            }

            // []
            case OPEN_ARRAY_DELIM: {
                // Local loop variables
                char * token = strtok(jsonCode, "[],");
                char ** values = malloc(sizeof(char*)+1);
                int iPos = 0;
                token = strtok(NULL, "[],");

                for (int i = 0; token != NULL; i++) {
                    i += strlen(token)+1;

                    token = strtok(NULL, "[],");
                }
                break;
            }

            // Break out of switch-case
            case ' ':
            default: {
                break;
            }
        }
    }
}

// Local Functions

// Removes all spaces that aren't inside of QUOTEs
char * removeSpacing(char * code) {
    bool isQuoted = false;
    char * newCode = malloc(strlen(code)+1);
    int newCodePtr = 0;

    for (int i = 0; i < strlen(code); i++) {
        switch (code[i])
        {
            case QUOTE: {
                isQuoted = !isQuoted;
                newCode[newCodePtr] = code[i];
                newCodePtr++;
                break;
            }
            case ' ': {
                if (isQuoted==true) {
                    newCode[newCodePtr] = code[i];
                    newCodePtr++;
                }
                break;
            }   
            default:
                newCode[newCodePtr] = code[i];
                newCodePtr++;
                break;
        }
        newCode[newCodePtr] = '\0';
    }
    printf(newCode);
    return newCode;
}