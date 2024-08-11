CC ?= gcc
CFLAGS = -Wall -Wextra
BIN_DIR = ./bin

compile:
	${CC} src/main.c lib/src/glad.c src/world/*.c -Ilib $(CFLAGS) -o $(BIN_DIR)/main -ldl -lglfw -lm

run: compile

.bin/main