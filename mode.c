#include "main.h"

/**
 * rem_spe - remove special characters
 *
 * @str: input string
 * Return: Modified string
 */
char *rem_spe(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * rem_ - remove spaces
 *
 * @str: input string
 * Return: Modified string
 */
char *rem_(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * nonint - Non-interactive mode
 *
 * @argv: argument variables
 */
/*void nonint(char **argv)
{
	char *input, *t_input, **tokens;
	int status, loop = 1;

	t_input = readline();
	if (!t_input)
		exit(0);
	input = rem_spe(t_input);
	if (input[0] == '\0')
	{
		free(t_input);
		exit(0);
	}
	tokens = tokenise(input);

	if (_strcmp(tokens[0], "exit") == 0)
		_xit(input, argv, tokens, loop);
	else
		status = execute(tokens, loop);
	free(t_input), freearray(tokens);
	exit(status);
}
*/
/**
 * int_mode - Interactive mode
 *
 * @argv: argument variables
 */
void int_mode(char **argv)
{
	char *input = NULL, **tokens;
	int status, loop = 0, read;
	size_t bufflen = 0;

	while (1)
	{
		loop++;
		if (isatty(STDIN_FILENO))
			prompt();
		read = getline(&input, &bufflen, stdin);
		if (read == EOF)
			exit(0);
		if (!input)
			break;
		/* input = rem_(input); */
		if (input[0] == '\0' || _strcmp(input, "\n") == 0)
		{
			free(input);
			continue;
		}
		tokens = tokenise(input);

		if (_strcmp(tokens[0], "exit") == 0)
			_xit(input, argv, tokens, loop);
		else
			status = execute(tokens, loop);
		free(input), freearray(tokens);
		continue;
	}
	exit(status);
}

