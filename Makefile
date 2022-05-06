ARGS=-g
CC=gcc $(ARGS)
AR=ar

ALL_O_FILES=files.o json.o string.o

# Testing files
test: main.o $(ALL_O_FILES)
	$(CC) -o test $^
main.o: src/main.c
	$(CC) -o main.o -c src/main.c

# Seaware library
seaware.a: $(ALL_O_FILES)
	$(AR) rcs libseaware.a $^
seaware.so: $(ALL_O_FILES)
	$(CC) -shared -o libseaware.so $^

# Seaware files
files.o: src/files.c files.h
	$(CC) -o files.o -c src/files.c
json.o: src/json.c json.h
	$(CC) -o json.o -c src/json.c
string.o: src/string.c string.h
	$(CC) -o string.o -c src/string.c

# PHONYs
.PHONY: clean
clean:
	rm -rf *.o
	rm -rf test