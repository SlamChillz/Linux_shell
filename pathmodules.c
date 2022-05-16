#include "main.h"

int prev;
char *op = NULL;

/**
 * path - check if the command exit in PATH
 * @token: array to to a string of characters
 *
 * Return: path, if found or NULL
 */
int path(char **token)
{
	int i = 0;
	char *path, **paths, *prev = token[0];
	struct stat st;

	if (prev[0] != '/')
	{
		paths = tokenise(_getenv("PATH"));
		while (paths[i])
		{
			path = join(paths[i], "/", prev);
			if (stat(path, &st) == 0)
			{
				token[0] = path;
				free(prev), freearray(paths);
				return (1);
			}
			free(path);
			i++;
		}
		freearray(paths);
	}
	else
	{
		if (stat(prev, &st) == 0)
			return (1);
	}
	printerror("./hsh", 1, prev);
	return (0);
}

/**
 * cut - create a array of tokens
 * @token: pointer to an array of strings
 * @n: number of strings to segment
 *
 * Return: array of strings
 */
char **cut(char **token, int n)
{
	int i = 0;
	char **t;

	t = malloc((n + 1) * sizeof(*t));
	if (t == NULL)
		return (NULL);
	while (i < n)
	{
		t[i] = _strdup(token[i]);
		i++;
	}
	t[i] = NULL;
	return (t);
}

/**
 * checkoperand - check if an operand exists in token
 * @str: array of characters
 *
 * Return: integer, 1 if present, 0 if not
 */
int checkoperand(char *str)
{
	if (_strcmp(str, "||") == 0)
		return (1);
	else if (_strcmp(str, "&&") == 0)
		return (1);
	else if (_strcmp(str, ";") == 0)
		return (1);
	else
		return (0);
}

/**
 * run - run command in snippets
 * @token: array of tokens
 *
 * Return: void
 */
void run(char **token)
{
	/* printf("%d\n", prev); */
	/*
	while (token[i])
	{
		print(token[i]);
		print("\n");
		i++;
	}
	return;
	*/
	if (op == NULL || _strcmp(op, ";") == 0)
	{
		prev = _execbuiltins(token);
		/* printf("%d\n", prev); */
		if (prev)
			prev = _execpath(token);
	}
	else if ((prev == 0) && (_strcmp(op, "&&") == 0))
	{
		prev = _execbuiltins(token);
		if (prev)
			prev = _execpath(token);
	}
	else if ((prev == 1) && (_strcmp(op, "||") == 0))
	{
		prev = _execbuiltins(token);
		if (prev)
			prev = _execpath(token);
	}
	return;
}

/**
 * execute - as the name implies, execute a command
 * @tokens: array of strings
 *
 * Return: exit status
 */
int execute(char **tokens)
{
	int i, n = 0;
	char **token;

	prev = -1, op = NULL;
	for (i = 0; tokens[i]; i++)
	{
		/* printf("%d\n", checkoperand(tokens[i])); */
		if (checkoperand(tokens[i]))
		{
			token = tokens + i - n;
			token = cut(token, n);
			run(token);
			free(token);
			op = tokens[i];
			n = 0;
			continue;
		}
		n++;
	}
	token = tokens + i - n;
	token = cut(token, n);
	run(token);
	free(token);
	return (prev);
}
