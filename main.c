#include "main.h"

/**
 * main - program entry
 * @argc: number of commandline arguments
 * @argv: array of commandline parameters
 *
 * Return: integer
 */
int main(int argc, char *argv[])
{
	char *input, **tokens;
	int loop = 0, status = 0;

	(void) (argc), (void) (argv);
	while (1)
	{
		loop++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = readline();
		if (!input)
			break;
		if (input[0] == '\0' || _strcmp(input, "\n") == 0)
		{
			free(input);
			continue;
		}
		tokens = tokenise(input);

		if (_strcmp(tokens[0], "exit") == 0)
			_xit(loop, input, argv, tokens);
		status = _execbuiltins(tokens);
		if (status == 0)
		{
			free(input), freearray(tokens);
			continue;
		}
	}
	exit(STATUS);
}

