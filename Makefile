# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Executable name
TARGET = hsh

# Source files
SRCS = main.c execute_line.c tokenizer.c execute_command.c resolve_path.c \
       builtins.c string_helpers.c error_handlers.c memory_helpers.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = shell.h

# Default target: build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule to build object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run the shell
run: $(TARGET)
	./$(TARGET)

# Phony targets (not real files)
.PHONY: all clean run
