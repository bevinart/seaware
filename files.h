#ifndef FILES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Read
char * read_file(char * filePath);
int get_file_size(char * filePath);

// Write
void create_file(char * filePath);
void append_file(char * filePath, char * content);

// Booleans
bool file_exists(char * filePath);

#define FILES_H
#endif