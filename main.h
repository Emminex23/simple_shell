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
int exe(char *command);
extern char **environ;


#endif
