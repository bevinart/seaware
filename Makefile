ARGS=-g
CC=clang $(ARGS)

ALL_O_FILES=main.o config.o files.o json.o string.o

test: $(ALL_O_FILES)
	$(CC) -o test $(ALL_O_FILES)

main.o: src/main.c
	$(CC) -o main.o -c src/main.c
config.o: src/config.c config.h
	$(CC) -o config.o -c src/config.c
files.o: src/files.c files.h
	$(CC) -o files.o -c src/files.c
json.o: src/json.c json.h
	$(CC) -o json.o -c src/json.c
string.o: src/string.c string.h
	$(CC) -o string.o -c src/string.c

clean:
	rm *.o
	rm test