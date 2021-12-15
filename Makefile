CC=cc
CFLAGS=-std=c99 -Wall -Wpedantic
OPT=-Os

build:
	$(CC) parser.c test.c $(CFLAGS) $(OPT) -o hex

debug:
	$(CC) parser.c test.c $(CFLAGS) -ggdb -o hex
