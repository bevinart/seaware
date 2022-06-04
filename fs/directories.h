#ifndef CWARE_DIRECTORIES_H
#define CWARE_DIRECTORIES_H

struct Directory {
    char * path;
    char ** files;
    struct Directory ** directories;
    struct Directory * prevDirectory;
};

void deleteDir();


#endif