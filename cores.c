#include "main.h"

/**
 * readline - read input from standard input
 *
 * Return: array of charcters
 */
char *readline(void)
{
	char buf[1024], *ptr = NULL, *ptr2;
	char ptrlen = 0;
	int buflen = 0;

	while (fgets(buf, 1024, stdin))
	{
		buflen = _strlen(buf);
		if (!ptr)
		{
			ptr = malloc(buflen + 1);
		}
		else
		{
			ptr2 = _realloc(ptr, ptrlen, ptrlen + buflen + 1);
			if (ptr2)
				ptr = ptr2;
			else
				free(ptr);
		}
		if (!ptr)
			return (NULL);

		_strcpy(ptr + ptrlen, buf);

		if (buf[buflen - 1] == '\n')
			return (ptr);
		ptrlen += buflen;
	}
	if (EOF)
	{
		if (ptr != NULL)
			free(ptr);
		_putchar('\n');
		return (NULL);
	}
	return (ptr);
}

/**
 * _execpath - execute path command
 * @token: array of strings
 *
 * Return: exit status
 */
int _execpath(char **token)
{
	pid_t pid;
	int wstatus;

	if (!path(token))
		return (1);

	if (!echocheck(token[0]))
	{
		if (!_echo(token))
			return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
	{
		if (execve(token[0], token, environ) == -1)
		{
			perror("Error:");
			exit(1);
		}
		exit(0);
	}
	else
	{
		wait(&wstatus);
	}
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	return (1);
}

/**
 * _execbuiltins - check if the command is a built in and execute
 * @tokens: array of strings
 *
 * Return: integer, status vaue
 */
int _execbuiltins(char **tokens)
{
	int i, status = 1;
	builtin b[] = {
	    {"cd", _chdir},
	    {"env", env},
	    {"echo", _echo},
	    {"setenv", _setenv},
	    {"unsetenv", _unsetenv},
	    {NULL, NULL}
	};

	for (i = 0; b[i].name; i++)
	{
		if (_strcmp(b[i].name, tokens[0]) == 0)
		{
			status = (b[i].func)(tokens);
			break;
		}
	}
	return (status);
}

/**
 * batch_mode: batch run a script
 *
 * @filename: name of file
 * Return: status
 */
int batch_mode(char *filename)
{
	FILE *fptr;
	int status;
	char line[1024];
	char **args;
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		perror("Error:");
		return (1);
	}
	else
	{
		while (fgets(line, sizeof(line), fptr) != NULL)
		{
			args = tokenise(line);
			status = execute(args);
			freearray(args);
		}
	}
	fclose(fptr);
	return (status);
}

