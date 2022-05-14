#include "main.h"

/**
 * _xit - exit the program with a status code
 * @n: loop count
 * @in: input from terminal
 * @argv: array of program name
 * @tokens: array of tokens
 *
 * Return: void
 */
void _xit(int n, char *in, char **argv, char **tokens)
{
	int i = 0, status;

	if (tokens[1] == NULL)
	{
		free(in), freearray(tokens);
		exit(EXIT_SUCCESS);
	}
	while (tokens[1][i])
	{
		if (_isalpha(tokens[1][i++]) != 0)
		{
			exiterror(argv, n, tokens);
			free(in), freearray(tokens);
			return;
		}
	}
	if (_atoi(tokens[1]) >= 0)
	{
		status = _atoi(tokens[1]);
		free(in), freearray(tokens);
		exit(status);
	}
	else if (_atoi(tokens[1]) < 0)
	{
		exiterror(argv, n, tokens);
		free(in), freearray(tokens);
	}
}

