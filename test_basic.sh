#!/bin/bash
# Test script for simple shell basic commands

echo "Testing 'ls'"
echo "ls" | ./hsh

echo "Testing 'env'"
echo "env" | ./hsh

echo "Testing 'unknown_command'"
echo "unknown_command" | ./hsh
