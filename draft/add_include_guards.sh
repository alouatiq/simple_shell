#!/bin/bash

# Find all .h files in the current directory and its subdirectories
for file in $(find . -name "*.h"); do
  # Create a unique guard name based on the file path
  GUARD=$(echo $file | tr '[:lower:]/' '[:upper:]_' | sed 's/[^A-Z0-9_]/_/g')

  # Check if the file already contains a guard
  if ! grep -q "#ifndef $GUARD" "$file"; then
    # Insert the include guard at the top of the file
    sed -i "1i#ifndef $GUARD\n#define $GUARD\n" "$file"

    # Append the closing guard at the bottom of the file
    echo "#endif /* $GUARD */" >> "$file"
  fi
done
