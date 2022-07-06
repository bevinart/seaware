#include "seaware.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// main.c : Testing file

int main(int argc, char * argv[]) {
    // Variables
    struct JSON * json = json_init();
    string str = new_string();
    str.value = str.add(str, 1, "    ThisIs    ");

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
    char * as_test = str.add(str, 3, "Another", "Test", "lamayo");
    printf("add_strings() result is: %s\n", as_test);


    printf("removeSubstr result is: %s\n\n", str.remove(str, "Thi"));

    printf("itos() result is: %s\n", itos(12));
    printf("ftos() result is: %s\n\n", ftos(12.1f));

    char * testStrDelim = "is";
    printf("split() result is: %s\n", split(str, testStrDelim)[0]);

    printf("trim() result is: %s\n", trim(str));

    free(str.value);

    return 0;
}