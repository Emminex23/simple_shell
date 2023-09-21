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

/*Macros*/
#define MAX 1024
#define BUFFERSIZE 1024

/*Prototypes*/
int exe(char *command); /*shell*/
int findpath(const char *command, char *path, size_t length);/*find path*/
unsigned int _strlen(const char *str); /*print*/
unsigned int _print(char *str);/*print*/
int _strncmp(const char *s1, const char *s2, size_t n);/*helper*/
char *_strdup(const char *src); /*helper*/
void *_memcpy(void *dest, const void *src, size_t n); /*helper*/
char *_strncpy(char *dest, const char *src, size_t n);/*helper*/
void exit_shell(void); /*helper*/
void print_env(void); /*print*/
int _strcmp(const char *str1, const char *str2); /*print*/
void handle_command(char *buffer);/*helper*/
void handle_read_error(void);/*helper*/
int main(void);/*entrypoint*/
extern char **environ;


#endif
