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
	int i, loop = 0, status = 0;

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
		i = 0;
		while (tokens[i])
			printf("%s\n", tokens[i++]);
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
		free(tokens);
	}
	exit(status);
}

