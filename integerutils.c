#include "main.h"

/**
 * _isalpha - Alphabet check
 * @c: parameter must be an integer value
 *
 * Return: 1 if c is a letter, else 0
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
		return (1);
	else
		return (0);
}

/**
 * _atoi - convert string to integer
 * @s: string to be coverted
 * Description: a function that convert a string to an integer.
 *
 * Return: integer else 0 if no number in the string
 */
int _atoi(char *s)
{
	int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}

