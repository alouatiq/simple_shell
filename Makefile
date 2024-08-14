CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
FILES = main.c builtins.c env.c execute.c getline.c path.c shell.c string_helpers.c tokenizer.c
OBJECTS = $(FILES:.c=.o)
TARGET = simple_shell

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET)
