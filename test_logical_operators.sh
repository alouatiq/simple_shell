#!/bin/bash

# Test script for the '&&' and '||' logical operators in simple shell

# Create a temporary file for input
TEMP_INPUT=$(mktemp)

# Function to clean up temporary files
cleanup() {
    rm -f "$TEMP_INPUT"
}

# Set up trap to clean up on exit
trap cleanup EXIT

# Function to run a command and print its output
run_command() {
    echo "$ $1"
    echo "$1" > "$TEMP_INPUT"
    ./hsh < "$TEMP_INPUT"
    echo
}

# Test 1: Simple AND operation
run_command "ls /var && echo 'success'"

# Test 2: Simple OR operation
run_command "ls /nonexistent || echo 'fallback'"

# Test 3: AND operation with failure
run_command "ls /nonexistent && echo 'should not print'"

# Test 4: Multiple AND operations
run_command "true && echo 'true works' && false && echo 'should not print'"

# Test 5: Multiple OR operations
run_command "false || echo 'false works' || true || echo 'should not print'"

# Test 6: Combination of AND and OR
run_command "true && echo 'true' || echo 'should not print'"

# Test 7: Combination of OR and AND
run_command "false || echo 'false' && echo 'should print'"

# Test 8: Complex combination
run_command "false && echo 'not printed' || echo 'printed' && echo 'also printed'"

# Test 9: Built-in commands with logical operators
run_command "cd /tmp && pwd && cd - && pwd"

# Test 10: Command not found with logical operators
run_command "nonexistentcommand || echo 'command not found'"

echo "Test script completed."
