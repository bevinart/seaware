#include "seaware.h"
#include <stdio.h>
#include <stdlib.h>

// main.c : Testing file

int main(int argc, char * argv[]) {
    // Variables
    struct JSON * json = json_init();
    
    // WARN HANDLE TEST
    WARN("This library is stil under development, please be considerate.\n");

    // FILES TEST
    // if (file_exists("./test.json")) {
    //     // JSON TEST {
    //     json = read_json(json, "./test.json");
    //     //    string test
    //     printf("JSON String is: %s\n", json->values[0][0]);
    //     //    array test
    //     printf("JSON Array is: %s\n", json->values[2][2]);
    //     //    navigation test
    //     printf("JSON Navigation is: %s\n", json->nextField[0]->values[0][1]);
    //     // }
    // }
    // else {
    //     // ERR HANDLE TEST
    //     ERR("Couldn't find 'test.json'\n");
    // }

    // STRINGS TEST
    char * as_test = add_strings(3, "Another", "Test", "lamayo");
    printf("add_strings() result is: %s\n", as_test);
    free(as_test);

    char * c = "c";
    char * removeSubStr = remove_substr("Precum", c);
    printf("countSubstr result is: %d\n", count_substr("there are 4 cccc's", c));
    printf("removeSubstr result is: %s\n\n", removeSubStr);
    free(removeSubStr);

    char * integer = itos(12);
    char * floatVal = ftos(12.1f);
    printf("itos() result is: %s\n", integer);
    printf("ftos() result is: %s\n\n", floatVal);
    free(integer);
    free(floatVal);

    char * testStr = "This is a test string!";
    char * testStrDelim = " is ";
    char ** splitTest = split(testStr, testStrDelim);
    printf("split() result is: %s\n", splitTest[1]);
    free(splitTest);

    return 0;
}