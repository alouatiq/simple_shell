```
simple_shell/
├── AUTHORS                   # List of all contributors to the project
├── README.md                 # Project description, usage, and features
├── hsh                       # Compiled executable for the shell
├── main.c                    # Entry point of the shell with the main loop
├── shell.h                   # Header file with function prototypes, macros, and global variables
├── builtins.c                # Implementations of built-in commands like `cd`, `exit`, `env`, `setenv`, and `unsetenv`
├── tokenizer.c               # Function for tokenizing input strings
├── getline_custom.c          # Custom implementation of getline, if needed
├── expand_vars.c             # Handles variable expansion (e.g., `$?`, `$$`)
├── exec_cmd.c                # Function to execute commands using `execve`
├── path_resolver.c           # Resolves commands in the PATH if not an absolute path
├── builtins_handler.c        # Checks if a command is a built-in and executes it
├── string_helpers.c          # Custom string manipulation functions
├── error_handlers.c          # Functions for error printing and management
├── memory_helpers.c          # Functions for memory allocation and freeing
├── test_basic.sh             # Basic functionality tests for the shell
├── test_advanced.sh          # Tests for advanced features like logical operators
└── test_edge_cases.sh        # Tests for edge cases and error handling
```
