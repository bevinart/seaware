# Project Details
cmake_minimum_required(VERSION 3.23)
project(seaware VERSION 0.2)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

add_library(seaware STATIC ./fs.h 
                        ./fs/files.c ./fs/files.h
                        ./fs/directories.c ./fs/directories.h
                        ./datatypes.h
                        "./datatypes/string.c" "./datatypes/string.h"
                        ./filetypes.h
                        ./filetypes/json.c ./filetypes/json.h
                        ./filetypes/ini.c ./filetypes/ini.h
            )

# Making Test exec (OPTIONAL)
add_executable(test main.c)
target_link_libraries(test seaware)