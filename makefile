# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Name of the executable
NAME = hsh

# Source files
SRC = $(wildcard *.c) \
	  $(wildcard builtins/*.c) \
	  $(wildcard execution/*.c) \
	  $(wildcard helpers/*.c) \
	  $(wildcard advanced/*.c) \
	  $(wildcard input_handlers/*.c)

# Object files
OBJ = $(SRC:.c=.o)

# Header files
HEADERS = shell.h

# Default target
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Rule to compile source files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove object files
clean:
	$(RM) $(OBJ)

# Full clean (fclean) to remove object files and the executable
fclean: clean
	$(RM) $(NAME)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re