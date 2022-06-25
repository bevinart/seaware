/*

    CURRENT PROBLEMS:
        - Cannot have more than one section at a time

*/

#include <ini.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int sectionCount = 1;
int varCount = 1;

// Global functions
// Sets up new struct INI * variable
struct INI * ini_init() {
    struct INI * newINI = malloc(sizeof(struct INI)+1);

    newINI->variablesPtr = 0;
    newINI->subSectionsPtr = 0;

    newINI->variables = malloc(sizeof(struct variable*)+1);
    newINI->subSections = malloc(sizeof(struct INI *)+1);

    *newINI->variables = NULL;
    *newINI->subSections = NULL;
    newINI->sectionName = NULL;
    newINI->nextSection = NULL;
    newINI->prevSection = NULL;

    return newINI;
}

// Interprets an INI file, with syntax defined in ../include/ini.h
struct INI * interpret(struct INI * ini, char * filePath) {
    // Loop Variables    
    char line[MAX_LINE_LENGTH];
    FILE * iniFile = fopen(filePath, "r");
    bool isSubsection = false;

    // Read line by line
    while(fgets(line, sizeof(line), iniFile)) {
        bool isComment = false;
        bool isQuoted = false;

        // A holding cell for all the bad defaults out there, stay safe out there...
        char holdingCell[MAX_HOLDING_CELL];
        int holdingCellPtr = 0;

        // For each character in line
        for (int i = 0; i < strlen(line); i++) {
            printf("%c", line[i]);
            // Prevents memory leaks in holdingCell
            holdingCell[holdingCellPtr] = '\0';

            // Interpret
            switch(line[i]) {

                // This contains some hazardous memory leaks
                // Move into section
                case SECTION_OPEN: {
                    // If you are in a subsection, get out of it
                    if (isSubsection == true) {
                        ini = ini->prevSection;
                        isSubsection = false;
                    }

                    // Init new section
                    struct INI * newSection = ini_init();

                    if (line[(i+1)]==SUBSECTION) {
                        isSubsection = true;
                        // Reallocate size of subSections array
                        ini->subSections =  realloc(ini->subSections, sizeof(struct INI *) * (ini->subSectionsPtr+sectionCount));
                        
                        // Set and enter new subSection
                        newSection->prevSection = ini;
                        ini->subSections[ini->subSectionsPtr] = newSection;
                        ini = ini->subSections[ini->subSectionsPtr];
                        ini->subSectionsPtr++;
                        i++;
                    }
                    else {
                        newSection->prevSection = ini;
                        ini->nextSection = newSection;
                        ini = ini->nextSection;
                    }

                    sectionCount++;
                    break;
                }

                // Set sectionName
                case SECTION_CLOSE: {
                    ini->sectionName = malloc(sizeof(char) * strlen(holdingCell));
                    strcpy(ini->sectionName, holdingCell);
                    break;
                }

                // Unfinished
                // Creates new subsection and moves into it
                case SUBSECTION: {
                    // isSubsection = true;
                    // struct INI * newSection = ini_init();
                    // while(strncmp(ini->sectionName, holdingCell, strlen(holdingCell)) != 0) {
                    //     printf(ini->sectionName);
                    //     ini = ini->prevSection;
                    // }
                    // ini->subSections =  realloc(ini->subSections, sizeof(struct INI *) * ini->subSectionsPtr+1);
                    // ini->subSections[ini->subSectionsPtr] = newSection;
                    // ini->subSections[ini->subSectionsPtr]->prevSection = ini;
                    // ini = ini->subSections[ini->subSectionsPtr];
                    // ini->subSectionsPtr++;
                    
                    break;
                }

                // This also contains hazardous material (memory leaks)
                // Creates new variable and assigns name and value
                case EQUALS: {
                    isQuoted = true;
                    struct variable * newVar = malloc(sizeof(struct variable)*(sizeof(line)+4));
                    char * value = strtok(line, EQUALS_PTR);

                    // Set variableName
                    newVar->variableName = malloc((sizeof(value)*varCount+1));
                    strcpy(newVar->variableName, value);

                    // After EQUALS
                    value = strtok(NULL, EQUALS_PTR);

                    // Set value
                    newVar->value = malloc((sizeof(value)*varCount+1));
                    strcpy(newVar->value, value);
                    
                    printf("%s", value);

                    // Add variable to ini field
                    ini->variables = realloc(ini->variables, sizeof(struct variable*)*(ini->variablesPtr+varCount));
                    ini->variables[ini->variablesPtr] = newVar;
                    ini->variablesPtr++;

                    varCount++;
                    break;
                }
                
                // Skips to new line
                case COMMENT: {
                    isComment = true;
                    break;
                }
                
                // Gets names and values
                default: {
                    holdingCell[holdingCellPtr] = line[i];
                    holdingCellPtr++;
                    break;
                }
            }
            if (isComment == true || isQuoted == true)
                break;
        }
    }

    // Stop reading file
    fclose(iniFile);

    // Loop back to beginning
    while(ini->prevSection != NULL) {
        ini = ini->prevSection;
    }

    // You get what you get, stop throwing a fit
    return ini;
}
