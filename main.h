#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/*secondary_functions*/
void freeStringArray(char **array);
void _putchar(const char *c);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
void string_rev(char *str, int len);
char *_itoa(int n);

/*main_functions*/
char *get_cmd(void);
char **split_input(char *input_command);
char *_getenv(char *variable_name);
char *get_cmd_path(char *command);
void printErrorMessage(char *name, char *cmd, int e_index);
int execute_cmd(char **command, char **argv, int index);
void print_environment(void);

#endif /* MAIN_H */
