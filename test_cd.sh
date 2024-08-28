#!/bin/bash

# Test script for the cd command in simple shell

# Function to run a command and print its output
run_command() {
    echo "$ $1"
    eval "$1"
    echo
}

# Test 1: cd with no arguments (should change to HOME)
run_command "cd"
run_command "pwd"

# Test 2: cd with a valid directory
run_command "cd /tmp"
run_command "pwd"

# Test 3: cd with an invalid directory
run_command "cd /nonexistent_directory"

# Test 4: cd - to change to the previous directory
run_command "cd -"
run_command "pwd"

# Test 5: cd ~ to change to the HOME directory
run_command "cd ~"
run_command "pwd"

# Test 6: Verify that PWD and OLDPWD environment variables are updated correctly
run_command "echo \$PWD"
run_command "echo \$OLDPWD"

# Test 7: cd to a relative path
run_command "cd .."
run_command "pwd"

# Test 8: cd to an absolute path
run_command "cd /usr/local"
run_command "pwd"

echo "Test script completed."
