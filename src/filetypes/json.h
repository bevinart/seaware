#ifndef JSON_H
#define JSON_H

// Added in case people want to change up the JSON syntax
#define DELIM ':'
#define OPEN_BLOCK_DELIM '{'
#define CLOSE_BLOCK_DELIM '}'
#define OPEN_ARRAY_DELIM '['
#define CLOSE_ARRAY_DELIM ']'
#define SEPARATOR ','
#define QUOTE '"'

#define MAX_VALUE_SIZE 255

#include "files.h"
#include "string.h"


struct JSON {
    // Field name, if no name, then NULL
    char * property;
    // All elements in current field
    char *** values;
    int VALUE_COUNT;

    // Field-to-Field
    /*
        "BLOCK-1": {
            ...
        }
        "BLOCK-2": {
            ...
        }
    */
    struct JSON ** nextField;
    int nextFieldSize;
    struct JSON * prevField;
};

// Can take a file or a string
// A.K.A Parses each object (God forbid you use a different JSON file)
/*
    {
        ...
    }
    {
        ...
    }
*/
struct JSON parse(char * jsonLocale);

// With these functions, 'struct JSON json' MUST BE IN FIELD WITH VALUE YOU WANT!!
// Adds new element in field
// "Property": "Value"
struct JSON append_element(struct JSON json, char * propertyName, char * value);
struct JSON change_element_name(struct JSON json, char * propertyName, char * newName);
struct JSON change_element_value(struct JSON json, char * propertyName, char * newValue);
// Removes all elements with that property name
struct JSON remove_element(struct JSON json, char * propertyName);
struct JSON output_json(struct JSON json, char * filePath);

#endif