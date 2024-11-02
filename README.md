```
simple_shell/
├── AUTHORS
│   - **Description**: Lists all contributors to the project.
│   - **Tasks**: Required for documentation purposes, specifying project contributors.
│
├── README.md
│   - **Description**: Provides a detailed description of the project, usage instructions, and features.
│   - **Tasks**: Required for documentation, explaining the purpose and use of the shell.
│
├── hsh
│   - **Description**: The compiled executable of the simple shell. Generated after running `make`.
│   - **Tasks**: Represents the final working shell, allowing interactive and non-interactive usage.
│
├── main.c
│   - **Description**: Contains the main loop for the shell, managing user input, parsing, and executing commands.
│   - **Tasks**:
│       - Task 1: Implements the basic shell loop that displays a prompt, reads input, and handles EOF.
│       - Task 4: Manages the exit functionality by checking return values from command execution.
│
├── shell.h
│   - **Description**: Header file containing all necessary includes, macros, and function prototypes used across the project.
│   - **Tasks**: Supports modularity by providing function prototypes and shared dependencies across files.
│
├── builtins.c
│   - **Description**: Implements built-in commands such as `exit`, `env`, and other shell-specific functionalities.
│   - **Tasks**:
│       - Task 4: Implements `exit` built-in to exit the shell.
│       - Task 5: Implements `env` built-in to print environment variables.
│       - Task 9 & 10 (advanced): Implements `setenv` and `unsetenv` for environment manipulation, and `cd` for directory changes.
│
├── tokenizer.c
│   - **Description**: Contains functions to split input lines into tokens (e.g., commands and arguments).
│   - **Tasks**:
│       - Task 1 & 2: Tokenizes user input for command processing, handling command lines with and without arguments.
│
├── getline_custom.c
│   - **Description**: Provides a custom implementation of `getline` to handle input reading, as required for advanced tasks.
│   - **Tasks**:
│       - Task 6 (advanced): Custom `getline` implementation to manage buffered input without using the standard library `getline`.
│
├── expand_vars.c
│   - **Description**: Handles variable expansion, replacing special variables like `$?` and `$$` with their respective values.
│   - **Tasks**:
│       - Task 14 (advanced): Supports variable replacement, specifically `$?` for last command status and `$$` for the shell’s PID.
│
├── exec_cmd.c
│   - **Description**: Executes commands by creating a child process and invoking `execve` to run the command.
│   - **Tasks**:
│       - Task 1: Handles command execution using `execve`.
│       - Task 3: Searches for commands in `PATH` and executes them if found.
│
├── path_resolver.c
│   - **Description**: Resolves commands by searching in the directories listed in `PATH` if the command is not an absolute path.
│   - **Tasks**:
│       - Task 3: Resolves commands by searching `PATH`, skipping `fork` if the command doesn’t exist.
│
├── builtins_handler.c
│   - **Description**: Checks if a command is a built-in command and, if so, executes the corresponding built-in function.
│   - **Tasks**:
│       - Task 1 & 4: Checks for built-in commands like `exit`, and executes them.
│       - Task 5: Executes the `env` command.
│       - Task 9 & 10 (advanced): Handles other built-ins like `setenv`, `unsetenv`, and `cd`.
│
├── string_helpers.c
│   - **Description**: Provides custom string manipulation functions to avoid dependency on standard library functions.
│   - **Tasks**:
│       - General utility to support string handling across tasks, including custom functions for `_strlen`, `_strcpy`, etc.
│
├── error_handlers.c
│   - **Description**: Manages error messages, formatting them according to project specifications.
│   - **Tasks**:
│       - Task 1, 2 & 3: Handles error reporting for invalid commands, missing paths, or syntax errors.
│
├── memory_helpers.c
│   - **Description**: Contains functions to assist with memory allocation, freeing, and reallocation as needed.
│   - **Tasks**:
│       - General support for memory management, preventing leaks across various tasks.
│
├── test_basic.sh
│   - **Description**: A test script to verify basic functionality, such as command execution, built-ins, and error handling.
│   - **Tasks**:
│       - Tests tasks 1, 2, 3, 4, and 5, verifying shell behavior with simple commands, built-ins, and error cases.
│
├── test_advanced.sh
│   - **Description**: A test script for advanced features like logical operators (`&&`, `||`) and multiple command handling.
│   - **Tasks**:
│       - Task 12 (advanced): Tests logical operators.
│       - Task 11 (advanced): Tests command separation with `;`.
│
└── test_edge_cases.sh
    - **Description**: A test script to check edge cases, ensuring the shell handles unexpected input and special cases gracefully.
    - **Tasks**:
        - Tests various edge cases across tasks, ensuring robustness against invalid input, empty commands, and special characters.

```
