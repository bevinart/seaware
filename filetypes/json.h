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

struct JSON {
    // Field name, if Global, then NULL
    char * property;

    char *** values;
    int valuesSize;

    struct JSON ** nextField;
    int nextFieldSize;
    struct JSON * prevField;
};

// MUST BE CALLED FIRST
// Initializes a new JSON struct
struct JSON * json_init();

// Parsing

// Allows for single values and arrays
struct JSON * add_variable(struct JSON * json, char * varName, char ** varValue);
struct JSON * add_field(struct JSON * json, char * fieldName);

// I/O

// JSON Interpreter
struct JSON * interpret_json(struct JSON * json, char * jsonCode);
// Reads and interprets JSON file and return new JSON struct
struct JSON * read_json(struct JSON * json, char * filePath);
// Outputs the given JSON struct into a JSON file
struct JSON * output_json(struct JSON json, char * filePath);

#endif