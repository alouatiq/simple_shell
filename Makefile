# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Executable name
TARGET = hsh

# Source files
SRCS = main.c execute_line.c tokenizer.c execute_command.c resolve_path.c \
       builtins.c string_helpers.c error_handlers.c memory_helpers.c

# Object files (automatically derived from source files)
OBJS = $(SRCS:.c=.o)

# Header files (to ensure changes to headers trigger recompilation)
HEADERS = shell.h

# Default target: build the executable only if dependencies are met
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule for object files, ensuring each file compiles independently
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run the shell after building
run: $(TARGET)
	./$(TARGET)

# Define phony targets to avoid conflicts with files named 'all', 'clean', or 'run'
.PHONY: all clean run
