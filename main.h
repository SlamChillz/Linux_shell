#ifndef SHELL
#define SHELL

#define BUFFERSIZE 1024
#define DELIMS " \t\r\n"

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int _intlen(int n);
int _strlen(char *s);
void _reverse(char *s);
char *_itoa(unsigned int n);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *copy(char *str, int n);

char *readline(void);
int _strcount(char *str);
char **tokenise(char *str);


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

int _putchar(char c);
void prompt(void);
void print(char *s);
void printerror(char *in, int n, char *name);

#endif /* SHELL */
