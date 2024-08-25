# Name of the output executable
TARGET = hsh

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# List of source files
SRCS = main.c shell_interactive.c shell_non_interactive.c \
       execute_command.c cd.c command_separator.c logical_operators.c \
       alias.c variable_replacement.c comments.c file_input.c \
       find_command_in_path.c handle_exit.c print_env.c \
       my_getline.c my_strtok.c

# List of object files (each .c file corresponds to a .o file)
OBJS = $(SRCS:.c=.o)

# Rule to build the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
# This compiles each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up the directory
# This removes all object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (these are not actual files)
.PHONY: all clean

# Default target (all), which builds the executable
all: $(TARGET)
