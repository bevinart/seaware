#ifndef SEAWARE_INI_H
#define SEAWARE_INI_H

#define MAX_HOLDING_CELL 255
#define MAX_LINE_LENGTH 255

// Syntax
#define QUOTES '"'
#define SECTION_OPEN '['
#define SUBSECTION '.'
#define SECTION_CLOSE ']'
#define VARIABLE_CALL '%'
#define COMMENT ';'
#define EQUALS '='
#define EQUALS_PTR "="

// Only one variableType for each variable
struct variable {
    char * variableName;
    char * value;
};

// The magic...
struct INI {
    // If NULL, you are global
    char * sectionName;
    // Like [.Test] or [Test1.Test]
    struct INI ** subSections;

    // Self explanitory
    struct variable ** variables;
    int subSectionsPtr;
    int variablesPtr;
    struct INI * nextSection;
    struct INI * prevSection;
};

struct INI * ini_init();
struct INI * interpret(struct INI * ini, char * filePath);

#endif