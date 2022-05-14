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
 * _execbuiltins - check if the command is a built in and execute
 * @tokens: array of strings
 *
 * Return: integer, status vaue
 */
int _execbuiltins(char **tokens)
{
	int i, status = 1;
	builtin b[] = {
		{"env", env},
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

