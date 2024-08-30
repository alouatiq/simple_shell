# Simple Shell

## Overview

This project is an implementation of a simple UNIX command-line interpreter (shell). It mimics the behavior of the `/bin/sh` shell with some additional features. The shell can execute commands both in interactive mode (where it displays a prompt and waits for user input) and in non-interactive mode (where it reads commands from a file or standard input).

## Features

- Executes commands found in the `PATH`.
- Built-in commands:
  - `exit`: Exits the shell.
  - `env`: Prints the current environment variables.
  - `setenv`: Initializes a new environment variable or modifies an existing one.
  - `unsetenv`: Removes an environment variable.
  - `cd`: Changes the current directory of the process.
  - `alias`: Handles command aliasing.
- Supports command line arguments.
- Handles command separators `;`.
- Supports logical operators `&&` and `||`.
- Variable replacement (`$?`, `$$`).
- Handles comments (`#`).
- Can execute commands from a file input.

## Compilation

To compile the shell, run the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Usage
### Interactive Mode
To start the shell in interactive mode:

```bash
./hsh
```
You will see a prompt (($)) where you can type commands.

### Non-Interactive Mode
You can also run the shell in non-interactive mode by providing a command or a file as input:

```bash
echo "/bin/ls" | ./hsh
```
Or by running commands from a file:
```bash
./hsh script.txt
```

### Built-in Commands
exit [status]: Exit the shell with an optional status code.
env: Display the environment variables.
setenv VARIABLE VALUE: Set or update an environment variable.
unsetenv VARIABLE: Remove an environment variable.
cd [DIRECTORY]: Change the current working directory.
alias [name[='value'] ...]: Manage aliases.

### Example
```bash
$ ./hsh
($) /bin/ls
README.md AUTHORS main.c shell.c hsh
($) cd ..
($) exit
```

### Testing
Ensure that your shell works in both interactive and non-interactive modes, producing output identical to /bin/sh.

## License
This project is open source and available under the MIT License.

graphql
Copy code

### `AUTHORS`

ALX

# Simple Shell Authors
AL OUATIQ H.