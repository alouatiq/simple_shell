# Simple Shell

This is a basic UNIX command line interpreter implemented in C. The shell displays a prompt and waits for the user to type a command. The command is then executed in a child process.

## Features

- Displays a prompt (`#cisfun$ `).
- Executes commands that are provided as a single word (no arguments).
- Handles errors and displays appropriate messages.
- Handles the end-of-file (EOF) condition (Ctrl+D).

## Compilation

To compile the shell, run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
```

## Usage
To run the shell, execute:

```bash
./shell
```

The shell will display the prompt and wait for commands. To exit, press Ctrl+D or type exit.
### Example
```bash

#cisfun$ /bin/ls
#cisfun$ exit
```

```go
### 6. `AUTHORS` - Contributors File
List the authors of the project.

```plaintext
Vasitha Sulem
Hassan AL OUATIQ
```

### Compilation Command
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
```

### Running the Shell
```bash
./shell
```

### Notes
- This implementation handles simple commands with no arguments and does not use the PATH variable.
- The shell correctly handles EOF (Ctrl+D) and displays an error message when a command cannot be executed.