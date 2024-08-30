CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
SRC = main.c prompt.c execute.c path.c input.c builtins.c env.c cd.c control_operators.c alias.c variables.c comments.c file_input.c
OBJ = $(SRC:.c=.o)
TARGET = hsh

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild
