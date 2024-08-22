# Compiler to use
CC = gcc

# Compiler flags to enforce strict standards and warnings
CFLAGS = -Wall -Werror -Wextra -pedantic

# Source files for the shell program
FILES = main.c builtins.c env.c execute.c getline.c path.c shell.c string_helpers.c tokenizer.c

# Object files, which are the compiled versions of the source files
OBJECTS = $(FILES:.c=.o)

# Name of the final executable
TARGET = simple_shell

# Rule to create the executable from the object files
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to clean up the object files and the executable
clean:
	rm -f $(OBJECTS) $(TARGET)
