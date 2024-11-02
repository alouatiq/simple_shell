# Name of the executable
NAME = hsh

# Compiler and compilation flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# List of source files
SRC = main.c shell.c exec.c path.c builtins.c env.c prompt.c error.c getline.c str_functions.c memory.c

# List of object files (replace .c with .o)
OBJ = $(SRC:.c=.o)

# Default target to build the executable
all: $(NAME)

# Rule to build the executable from object files
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Rule to build object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Recompile everything from scratch
re: fclean all

# Test script target
test: all
	./tests/test_shell.sh

# Phony targets (these targets are not files)
.PHONY: all clean fclean re test
