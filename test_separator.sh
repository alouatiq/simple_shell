#!/bin/bash

# Test script for the ';' command separator in simple shell

# Function to run a command and print its output
run_command() {
    echo "$ $1"
    echo "$1" | ./hsh
    echo
}

# Test 1: Single command
run_command "ls"

# Test 2: Two commands separated by ';'
run_command "ls ; pwd"

# Test 3: Multiple commands separated by ';'
run_command "echo Hello ; ls -l ; pwd"

# Test 4: Commands with arguments
run_command "echo First command ; echo Second command ; echo Third command"

# Test 5: Empty commands (should be ignored)
run_command "ls ; ; pwd"

# Test 6: Spaces around separators
run_command "echo A  ;  echo B  ;  echo C"

# Test 7: Built-in commands
run_command "cd /tmp ; pwd ; cd - ; pwd"

# Test 8: Command not found
run_command "ls ; nonexistentcommand ; pwd"

# Test 9: Exit command
run_command "echo Before exit ; exit ; echo After exit"

echo "Test script completed."
