#include "main.h"

/**
 * _strlen - calculate string length
 * @s: string whose length is to be determined
 * Description: a function that returns the length of a string.
 *
 * Return: integer(sum of string characters)
 */
int _strlen(char *s)
{
	int i = 0, sum = 0;

	while (s[i] != '\0')
	{
		sum = sum + 1;
		i++;
	}
	return (sum);
}

/**
 * _strcpy - copy str1 into str2
 * @dest: string to copy into
 * @src: string to copy from
 * Description:  a function that copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer pointed to by dest.
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (&dest[0]);
}

/**
 * _intlen - calculate length of an interger
 * @n: integer
 *
 * Return: integer, length of given integer
 */
int _intlen(int n)
{
	int len = 0;

	while (n)
		len++, n /= 10;

	return (len);
}

/**
 * _itoa - convert an integer to a string
 * @n: unsigned integer
 *
 * Return: string pointer
 */
char *_itoa(unsigned int n)
{
	int len = _intlen(n), i = 0;
	char *s = malloc(len + 1);

	if (s == NULL)
		return (NULL);

	for ( ; n / 10; i++)
		s[i] = (n % 10) + '0', n /= 10;
	s[i] = '\0';
	_reverse(s);
	return (s);
}

/**
 * _reverse - reverse a string
 * @s: string to be reverse
 * Description: a function that reverses a string.
 *
 * Return: None
 */
void _reverse(char *s)
{
	int i = 0, x = 0, y;

	while (s[i] != '\0')
	{
		i++;
	}
	i--;
	while (i > x)
	{
		y = s[i];
		s[i--] = s[x];
		s[x++] = y;
	}
}

