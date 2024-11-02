#!/bin/bash

# Test simple commands
echo "/bin/ls" | ./hsh
echo "pwd" | ./hsh

# Test invalid command
echo "invalid_command" | ./hsh

# Test built-in exit
echo "exit" | ./hsh
