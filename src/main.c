#include "../seaware.h"

// Testing file

int main(int argc, char * argv[]) {
    cfg conf;
    char * anotherTest[255][255];
    anotherTest[0][0] = "Test ";
    anotherTest[0][1] = " ing";
    
    // files check
    // if (file_exists("test-file.cfg")==true) {
    //     remove("test-file.cfg");
    // }
    // create_file("test-file.cfg");
    // append_file("test-file.cfg", print_config(conf));
    printf("%s", read_file("test-file.cfg"));
    printf("%i\n", get_file_size("test-file.cfg"));
    conf = read_config(read_file("test-file.cfg"), ':'); 

    return 0;
}