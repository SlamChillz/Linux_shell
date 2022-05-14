#ifndef SHELL
#define SHELL

#define BUFFERSIZE 1024 /* size of buffer memory */
#define DELIMS " \t\r\n" /* delimeters */
#define STATUS 0 /* exit status */

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

int _isalpha(int c);
int _atoi(char *s);

char *readline(void);
int _strcount(char *str);
char **tokenise(char *str);
void _xit(int n, char *in, char **argv, char **tokens);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freearray(char **array);

int _putchar(char c);
void prompt(void);
void print(char *s);
void printerror(char *in, int n, char *name);
void exiterror(char **argv, int n, char **tokens);

#endif /* SHELL */
