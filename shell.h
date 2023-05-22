#ifndef SHELL_H
#define SHELL_H

/*include libraries*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>

/*PROTOTYPES*/
/*main.c*/
void interactive(void);
void no_interactive(void);

/*interactive_shell.c*/
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);

/*exec_args.c*/
int new_process(char **args);

/*Builtin functions*/
int my_env(char **args);
int my_exit(char **args);
int my_cd(char **args);

/* custom_strcmp */
int _strcmp(const char *str1, const char *str2);

/*MACROS*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;


#endif
