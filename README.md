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

## Usage
Interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) exit
$
```

Non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
```

## Authors
[Your Name]
[Partner's Name]

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.