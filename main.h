#ifndef MAIN_H
#define MAIN_H

/*Header Files*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stddef.h>

/*Macros*/
#define MAX 1024
#define BUFFERSIZE 1024

/*Prototypes*/
int exe(char *command);
int findpath(const char *command, char *path, size_t length);
unsigned int _strlen(const char *str);
unsigned int _print(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *src);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strncpy(char *dest, const char *src, size_t n);
void exit_shell(void);
void print_env(void);
int _strcmp(const char *str1, const char *str2);
void handle_command(char *buffer, char *program_name, int line_number);
void handle_read_error(void);
int main(int argc, char *argv[]);
void clean_up_before_exit(void);
void sigint_handler(int sig);
char **parse_command(char *command, char **resolved_path_ref);
int execute_command(char **input, char *resolved_path);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
char *tokenisation(char *str, char delimiter);
extern char **environ;

/**
 * struct command_s - handles the commands
 * @name: command name
 * @func: function pointers for command
 *
 * Description: structure for handling
 * specifier formats
 */
typedef struct command_s
{
	char *name;
	void (*func)();
} command_t;


#endif
