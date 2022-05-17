#include "main.h"

/**
 * _putchar - print a character to the standard input
 * @c: character
 *
 * Return: void
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * prompt - display shell interactive prompt
 *
 * Return: void
 */
void prompt(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, signal_handr);
	print("($) ");
}

/**
 * signal_handr - handle signals
 *
 * @signum: Signal value
 */
void signal_handr(int signum)
{
	(void) (signum);

	print("\n($) ");
	fflush(stdout);
}

/**
 * print - print a string to standard output
 * @s: pointer to a string
 *
 * Return: void
 */
void print(char *s)
{
	write(STDOUT_FILENO, s, _strlen(s));
}

/**
 * printerror - print error message and shell loop count
 * @in: pointer to an array of strings, user input
 * @n: number of shell loop
 * @name: pointer to program name
 *
 * Return: void
 */
void printerror(char *name, char *in)
{
	char *e = _itoa(loop);

	print(name);
	print(": ");
	print(e), free(e);
	print(": ");
	print(in);
	print(": not found\n");
}

/**
 * exiterror - print error message and shell loop count
 * @argv: pointer to an array of strings, user input
 * @n: number of shell loop
 * @tokens: pointer to program name
 *
 * Return: void
 */
void exiterror(char **argv, char **tokens)
{
	char *e = _itoa(loop);

	print(argv[0]), print(": "), print(e), print(": ");
	print(tokens[0]), print(": Illegal number: "), print(tokens[1]);
	print("\n"), free(e);
}
