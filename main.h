#ifndef SHELL
#define SHELL

#define BUFFERSIZE 1024	  /* size of buffer memory */
#define DELIMS " :\t\r\n" /* delimeters */
#define STATUS 0	  /* exit status */

extern char **environ;
extern int loop;
extern int status;

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <limits.h>
#include <sys/stat.h>
#include <signal.h>

void int_mode(char **argv);
void nonint(char **argv);
int _intlen(int n);
int _strlen(char *s);
void _reverse(char *s);
char *_itoa(unsigned int n);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *copy(char *str, int n);
char *join(char *s1, char *s2, char *str3);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);

int _isalpha(int c);
int _atoi(char *s);

char *readline(void);
char *rem_(char *str);
char *rem_spe(char *str);
int _strcount(char *str);
char **tokenise(char *str);

void _xit(char *in, char **argv, char **tokens);
int env(char **tokens);
int _setenv(char **tokens);
int _unsetenv(char **tokens);
char *_getenv(char *var);
int _chdir(char **tokens);
int _execbuiltins(char **tokens);
int path(char **token);
int checkoperand(char *str);
char **cut(char **token, int n);
void run(char **token, int *prev, char *op);
int echocheck(char *str);
int _echo(char **token);
int _execpath(char **token);
int execute(char **tokens);
int batch_mode(char *filename);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freearray(char **array);

int _putchar(char c);
void prompt(void);
void print(char *s);
void signal_handr(int signum);
void printerror(char *in, char *name);
void exiterror(char **argv, char **tokens);
typedef void (*sighandler_t)(int);

/**
 * struct builtin - structure for custom built in functions
 * @name: string, name of the builtin
 * @func: pointer to a function to execute
 */
typedef struct builtin
{
	char *name;
	int (*func)(char **);
} builtin;

#endif /* SHELL */
