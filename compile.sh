#!/bin/bash

# Compile the simple shell project

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
    main.c \
    input_handlers/*.c \
    execution/*.c \
    builtins/*.c \
    helpers/*.c \
    helpers/missing_functions.c \
    advanced/*.c \
    -o hsh

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable 'hsh' created."
else
    echo "Compilation failed. Please check the error messages above."
fi
