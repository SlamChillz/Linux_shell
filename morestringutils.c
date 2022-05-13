#include "main.h"

/**
 * _strncpy - copy string
 * @dest: pointer to a char variable to be modified
 * @src: pointer to a character variable to be copied
 * @n: length of characters to be copied
 * Description: a function that copies a string.
 * - The function should work exactly like strncpy
 * Return: pointer to @dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compare two stings
 * @s1: first operand
 * @s2: second operand
 * Description: a function that compares two strings.
 * Return: integer, < or = or > 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
		;
	return (s1[i] - s2[i]);
}

