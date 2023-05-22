#ifndef SHELL_H
#define SHELL_H

/*include libraries*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>

/*PROTOTYPES*/
/*main.c*/
void interactive(void);

/*interactive_shell.c*/
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);

/*exec_args.c*/
int new_process(char **args);

/*Builtin functions*/
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);

/*MACROS*/
#define TOK_DELIM " \t\r\n\a\""

/*test*/
int no_interactive(void);
extern char **environ;


#endif
