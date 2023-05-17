# Simple Shell Project

This is a simple UNIX command interpreter project written in C language. It is designed to work similarly to the `/bin/sh` shell and can handle basic shell commands.

## Background

The project aims to help users understand the workings of a shell. It covers topics such as process identification (`pid`) and parent process identification (`ppid`), environment manipulation, process creation, system calls and functions, and the use of the `PATH` environment variable to locate programs.

## List of allowed functions and system calls

The following functions and system calls are allowed for this project:

- access
- chdir
- close
- closedir
- execve
- exit
- _exit
- fflush
- fork
- free
- getcwd
- getline
- getpid
- isatty
- kill
- malloc
- open
- opendir
- perror
- read
- readdir
- signal
- stat (__xstat)
- lstat (__lxstat)
- fstat (__fxstat)
- strtok
- wait
- waitpid
- wait3
- wait4
- write

## Compilation

The shell can be compiled using the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing

The shell can be tested using the interactive and non-interactive modes. In interactive mode, the prompt is displayed each time a command has been executed. In non-interactive mode, the command is passed through a file or a pipe. Here are some examples:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) exit
$
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Simple shell versions

### Simple shell 0.1

This version of the shell displays a prompt and waits for the user to enter a command. It can handle one-word commands only.

### Simple shell 0.1+

This version of the shell can handle command lines with arguments.

### Simple shell 0.2+

This version of the shell can handle the `PATH` environment variable and will not call `fork` if the command does not exist.

### Simple shell 0.3+

This version of the shell implements the `exit` built-in, which allows the user to exit the shell.

### Simple shell 1.0

This version of the shell implements the `env` built-in, which prints the current environment.

## Collaborators

- [JoseKariz](https://github.com/Josekariz) :smiley:
- [Marrionette](https://github.com/Shewanji) :star:

We hope this project helps you in understanding the basics of shell programming. Happy coding! :rocket: