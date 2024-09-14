# Simple Shell

## Description
This is a simple UNIX command line interpreter created as part of the ALX Software Engineering program. It aims to replicate basic functionalities of the standard shell (sh).

## Features
- Display a prompt and wait for the user to type a command
- Handle command lines with arguments
- Handle the PATH
- Implement built-in commands: exit, env, cd
- Handle the command separator ;
- Handle && and || logical operators
- Handle variables replacement
- Handle comments (#)
- Support file input

## Compilation
The shell can be compiled using:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Stracture
Interactive mode:
```
simple_shell/
│
├── README.md              # Task 0: Project description and usage instructions
├── AUTHORS                # List of contributors
├── man_1_simple_shell     # Man page for the shell
│
├── main.c                 # Tasks 1-5: Entry point of the shell, main loop
├── shell.h                # Main header file
│
├── input_handlers/
│   ├── read_line.c        # Task 6: Custom getline function
│   └── parse_input.c      # Tasks 2, 7: Tokenize and parse user input
│
├── execution/
│   ├── execute_command.c  # Tasks 1-3: Execute parsed commands
│   ├── path_handler.c     # Task 3: Handle PATH for command execution
│   └── fork_command.c     # Tasks 1-3: Create child process for command execution
│
├── builtins/
│   ├── builtin_handler.c  # Tasks 4, 5, 9, 10, 13: Identify and execute builtin commands
│   ├── exit.c             # Tasks 4, 8: Exit builtin
│   ├── env.c              # Task 5: Env builtin
│   ├── setenv.c           # Task 9: Setenv builtin
│   ├── unsetenv.c         # Task 9: Unsetenv builtin
│   ├── cd.c               # Task 10: Cd builtin
│   └── alias.c            # Task 13: Alias builtin
│
├── helpers/
│   ├── string_helpers.c   # Various tasks: String manipulation functions
│   ├── memory_helpers.c   # Various tasks: Memory allocation and freeing functions
│   └── error_handlers.c   # Various tasks: Error handling and printing functions
│
├── advanced/
│   ├── logical_ops.c      # Task 12: Handle && and || operators
│   ├── variable_expansion.c # Task 14: Handle $? and $$ variables
│   ├── comment_handler.c  # Task 15: Handle # comments
│   └── file_input.c       # Task 16: Handle file as input
│
└── tests/                 # Test files for various functionalities
	├── test_main.c
	└── ...
```


## Authors
AL OUATIQ H.
SULEM V.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
