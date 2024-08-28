# Simple Shell Project

## Description
This project is a simple UNIX command interpreter (shell) implemented in C. It's designed to mimic basic functionalities of the /bin/sh shell.

## Features
- Display a prompt and wait for user input
- Execute simple commands (no pipes, redirections, or advanced features)
- Handle command lines with arguments
- Handle the PATH
- Implement built-in commands: exit, env, cd
- Handle the end-of-file condition (Ctrl+D)

## Compilation
The shell will be compiled this way:
```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```

## Usage
```./hsh```

## Authors
- Vasitha Sulem
- Hassan AL OUATIQ

## Requirements
- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 20.04 LTS using gcc
- Code should use the Betty style
- No more than 5 functions per file
- All header files should be include guarded
- Use system calls only when necessary

## Files
- `main.c`: Entry point of the shell
- `shell.h`: Header file containing function prototypes and necessary includes
- `execute.c`: Functions for command execution
- `builtins.c`: Implementation of built-in commands
- `helpers.c`: Helper functions for string manipulation, etc.

## Setup
1. Clone the repository
2. Compile the shell using the compilation command mentioned above
3. Run the shell

## Testing
To test the shell, run it and try various commands:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) exit
$
```

## Contributing
Please read CONTRIBUTING.md for details on our code of conduct, and the process for submitting pull requests.

## License
This project is licensed under the MIT License - see the LICENSE.md file for details.