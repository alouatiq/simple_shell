# Simple Shell

## Overview

This project is a simple UNIX command line interpreter (shell) written in C. It replicates the basic functionality of standard UNIX shells like `bash` or `sh`. The shell allows users to interact with the operating system by executing commands, managing processes, and working with files through a text-based interface.

## Features

- **Interactive Mode**: The shell provides a prompt `#cisfun$ ` and waits for user input. It executes the entered command and then displays the prompt again.
- **Non-Interactive Mode**: The shell can execute commands from a file or input stream without displaying a prompt.
- **Command Execution**: Supports executing commands located in the system's `PATH` environment variable.
- **Command Line Arguments**: Handles command lines with arguments, allowing for more complex command execution.
- **Built-in Commands**: Implements basic built-in commands like `cd`, `exit`, and `env`.
- **Enhanced Exit Command**: The `exit` command now accepts an optional status argument for custom exit codes.
- **Environment Variable Handling**: Supports environment variables, including special variables like `$$` and `$?`.
- **Command Separators**: Allows executing multiple commands separated by `;`.
- **Logical Operators**: Supports logical operators `&&` and `||` for conditional command execution.
- **Alias Management**: Allows the creation, listing, and removal of command aliases.
- **Comment Handling**: Ignores any input following a `#`, treating it as a comment.
- **Memory Management**: Implements proper memory allocation and deallocation to prevent memory leaks.

## Files

- `main.c`: The entry point of the shell. Determines if the shell runs in interactive or non-interactive mode.
- `shell.h`: Header file containing all function declarations and macros.
- `shell_interactive.c`: Handles the shell's interactive mode.
- `shell_non_interactive.c`: Handles the shell's non-interactive mode.
- `execute_command.c`: Contains logic for executing commands.
- `cd.c`: Implements the `cd` built-in command.
- `command_separator.c`: Handles commands separated by `;`.
- `logical_operators.c`: Implements logical operators `&&` and `||`.
- `alias.c`: Manages command aliases.
- `variable_replacement.c`: Handles variable replacement such as `$$` and `$?`.
- `comments.c`: Removes comments from command input.
- `file_input.c`: Handles execution of commands from a file.
- `find_command_in_path.c`: Searches for commands in the `PATH`.
- `handle_exit.c`: Implements the `exit` built-in command.
- `print_env.c`: Implements the `env` built-in command.
- `my_getline.c`: Custom implementation of the `getline` function.
- `my_strtok.c`: Custom implementation of the `strtok` function.

## Compilation

To compile the shell, use the provided `Makefile`. Simply run:

```bash
make
```

This will compile the source files and produce an executable named `hsh`.

## Usage

### Interactive Mode

To run the shell in interactive mode, simply execute:

```bash
./hsh
```

You will see the prompt `$ `, where you can start typing commands.

### Non-Interactive Mode

To execute commands from a file, use:

```bash
./hsh < script.sh
```

### Example Commands

```bash
$ ls
$ pwd
$ cd /path/to/directory
$ exit
$ exit 98
$ /bin/ls -l /tmp
$ echo "Hello, World!"
$ ls -l && echo "Command succeeded" || echo "Command failed"
```

The shell now supports command lines with arguments and an updated 'exit' command that can take an optional status argument. The logical operators '&&' and '||' are also supported for conditional command execution.

## Contributors

- Hassan AL OUATIQ
- Vasitha Sulem
