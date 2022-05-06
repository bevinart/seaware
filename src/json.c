#include "../json.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct JSON parse(char * jsonLocale) {
    // Allocating variables
    struct JSON * jsonStruct = malloc(sizeof(struct JSON));
    jsonStruct->prevField = NULL;
    jsonStruct->VALUE_COUNT = 0;
    jsonStruct->nextFieldSize = 0;
    char * json = malloc(strlen(jsonLocale)+1);

    // File Check
    if (file_exists(jsonLocale))
        json = realloc(json, get_file_size(jsonLocale)+1);

    // If file exists, read it, otherwise, read string
    strcpy(json, (file_exists(jsonLocale)) ? read_file(jsonLocale) : jsonLocale);
    strcat(json, "\0");

    // Removes all spacing
    json = remove_char(json, ' ');
    json = remove_char(json, '\n');

    // Local Interpreter variables
    int BLOCK_COUNT = 0;
    jsonStruct->nextField = malloc(sizeof(struct JSON *));  // idk where to place this
    char pHolder[MAX_VALUE_SIZE];
    int pHolderPtr = 0;

    // For every character in JSON...
    for (int i = 0; i < strlen(json); i++) {
        // The interpreter .. .... .. 
        switch (json[i]) {

            // :
            case DELIM: {
                // If NOT opening a new block
                if (json[i+1]!='{') {
                    // Allocate values to include 2 values
                    jsonStruct->values[jsonStruct->VALUE_COUNT] = malloc(sizeof(char**)*2);
                    jsonStruct->values[jsonStruct->VALUE_COUNT][0] = malloc(sizeof(char*)*strlen(pHolder));
                    // Adding element name
                    pHolder[pHolderPtr] = '\0';
                    strcpy(jsonStruct->values[jsonStruct->VALUE_COUNT][0], pHolder);
                    pHolder[0] = '\0';
                    pHolderPtr = 0;
                }
                break;                
            }

            // ,
            case SEPARATOR: {
                // NOT going out of a block
                if (json[i-1]!='}') {
                    // Save last value
                    jsonStruct->values[jsonStruct->VALUE_COUNT][1] = malloc(sizeof(pHolder));
                    pHolder[pHolderPtr] = '\0';
                    strcpy(jsonStruct->values[jsonStruct->VALUE_COUNT][1], pHolder);

                    // Increase # of values
                    jsonStruct->VALUE_COUNT++;

                    // Reset
                    pHolder[0] = '\0';
                    pHolderPtr = 0;
                }
                break;
            }

            // {
            case OPEN_BLOCK_DELIM: {
                // if not opening of new JSON
                if (BLOCK_COUNT==0) {
                    // Set title to NULL
                    jsonStruct->property = NULL;
                }
                // Blocks
                // "Block": {}
                else {
                    // Allocates memory and assigns for next field to enter
                    struct JSON * nextField = malloc(sizeof(struct JSON));
                    nextField->nextField = malloc(sizeof(struct JSON *));
                    nextField->VALUE_COUNT = 0;
                    nextField->nextFieldSize = 0;

                    // Node machine
                    nextField->prevField = jsonStruct;
                    jsonStruct->nextField[jsonStruct->nextFieldSize] = nextField;
                    jsonStruct = jsonStruct->nextField[jsonStruct->nextFieldSize];

                    // Gets block name
                    pHolder[pHolderPtr] = '\0';
                    jsonStruct->property = malloc(sizeof(char*)*strlen(pHolder));
                    strcpy(jsonStruct->property, pHolder);
                    pHolder[0] = '\0';
                    pHolderPtr = 0;
                }

                // Allocates values
                jsonStruct->values = malloc(sizeof(char***));
                // We in one block
                BLOCK_COUNT++;
                break;
            }
            // }
            case CLOSE_BLOCK_DELIM: {
                // Gets last value from block
                if (json[i-1]!='}') {
                    pHolder[pHolderPtr] = '\0';
                    jsonStruct->values[jsonStruct->VALUE_COUNT][1] = malloc(sizeof(pHolder));
                    strcpy(jsonStruct->values[jsonStruct->VALUE_COUNT][1], pHolder);
                    jsonStruct->VALUE_COUNT++;
                    pHolder[0] = '\0';
                    pHolderPtr = 0;
                }


                // To not confuse whats closing a block or closing JSON
                if (jsonStruct->prevField != NULL) {
                    jsonStruct = jsonStruct->prevField;
                }

                // We out of one block
                jsonStruct->nextFieldSize++;
                BLOCK_COUNT--;
                break;
            }

            // []
            case OPEN_ARRAY_DELIM: {
                // Starts at 1 since 0 is the element name
                int arrLen = 1;

                // Value getter variables
                char str[255];
                int strPtr = 0;

                // Skips OPEN_ARRAY_DELIM so that it doesn't interfere with the name or value
                i++;
                // Another interpreter for the line
                // Increases the interpreter value
                for (; json[i] != CLOSE_ARRAY_DELIM; i++) {
                    // if : or ] (Split or last value)
                    if (json[i] == SEPARATOR || json[i+1] == CLOSE_ARRAY_DELIM) {
                        // Reallocates size to fit more than 2 or whatever the current size is
                        jsonStruct->values[jsonStruct->VALUE_COUNT] = realloc(jsonStruct->values[jsonStruct->VALUE_COUNT], sizeof(char**) * arrLen+1);
                        
                        // Allocates and adds value
                        jsonStruct->values[jsonStruct->VALUE_COUNT][arrLen] = malloc(sizeof(char*)*strlen(str));
                        str[strPtr] = '\0';
                        strcpy(jsonStruct->values[jsonStruct->VALUE_COUNT][arrLen], str);
                        str[0] = '\0';
                        strPtr = 0;

                        // Increase array size for adding values
                        arrLen++;
                        continue;
                    }
                    // Ignore quotes
                    else if (json[i] == QUOTE) {
                        continue;
                    }

                    // Gets values
                    else {
                        str[strPtr] = json[i];
                        strPtr++;
                        continue;
                    }
                }
                
            }

            // "" Ignored
            case QUOTE: {
                break;
            }
            
            // Grabs element name or value
            default: {
                pHolder[pHolderPtr] = json[i];
                pHolderPtr++;
                break;
            }
        }
        continue;
    }

    // Freeing variables
    free(json);

    return *jsonStruct;
}