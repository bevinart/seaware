#ifndef CWARE_FILES_H

// Read
char * read_file(char * filePath);
int get_file_size(char * filePath);

// Write
void create_file(char * filePath);
void append_file(char * filePath, char * content);

// Booleans
int file_exists(char * filePath);

#define CWARE_FILES_H
#endif