#include "main.h"

int status, loop = 0;
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

	if (argc == 2)
	{
		status = batch_mode(argv[1]);
		exit(status);
	}
	else
	{
		loop = 0;
		(void)(argc), (void)(argv);
		while (1)
		{
			loop++;
			if (isatty(STDIN_FILENO))
				prompt();
			input = readline();
			if (!input)
				break;
			if (input[0] == '\0' || _strcmp(input, " \n") == 0 || _strcmp(input, "\n") == 0)
			{
				free(input);
				continue;
			}
			tokens = tokenise(input);

			if (_strcmp(tokens[0], "exit") == 0)
				_xit(input, argv, tokens);
			else
				status = execute(tokens);
			free(input), freearray(tokens);
			continue;
		}
	}
	exit(status);
}
