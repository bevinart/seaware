#include "seaware.h"
#include <stdio.h>

// main.c : Testing file

int main(int argc, char * argv[]) {
    // Variables
    struct JSON json;
    
    // WARN HANDLE TEST
    WARN("This library is stil under development, please be considerate.\n");

    // FILES TEST
    if (file_exists("./test.json")) {
        // JSON TEST {
        json = parse("./test.json");
        //    string test
        printf("JSON String is: %s\n", json.values[0][0]);
        //    array test
        printf("JSON Array is: %s\n", json.values[2][2]);
        //    navigation test
        printf("JSON Navigation is: %s\n", json.nextField[0]->values[0][1]);
        // }
    }
    else {
        // ERR HANDLE TEST
        ERR("Couldn't find 'test.json'\n");
    }

    // STRINGS TEST
    char * as_test = add_strings(3, "Another", "Test", "lamayo");
    printf("add_strings() result is: %s\n", as_test);

    printf("itos() result is: %s\n", itos(12));
    printf("ftos() result is: %s\n", ftos(12.1f));

    return 0;
}