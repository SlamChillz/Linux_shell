#include "main.h"

/**
 * _chdir - change current work directory
 * @tokens: array of strings
 *
 * Return: integer, execution status
 */
int _chdir(char **tokens)
{
	char cwd[PATH_MAX];
	char *arr[4];
	int status;

	if (tokens[1] == NULL)
	{
		status = chdir(_getenv("HOME"));
	}
	else if (_strcmp(tokens[1], "-") == 0)
	{
		print(_getenv("OLDPWD")), print("\n");
		status = chdir(_getenv("OLDPWD"));
	}
	else
	{
		status = chdir(tokens[1]);
	}
	if (status == -1)
	{
		perror("hsh");
		return (-1);
	}
	getcwd(cwd, sizeof(cwd));
	if (cwd == NULL)
	{
		perror("hsh");
		return (-1);
	}
	arr[0] = "setenv", arr[1] = "OLDPWD", arr[2] = _getenv("PWD");
	arr[3] = NULL;
	_setenv(arr);
	arr[0] = "setenv", arr[1] = "PWD", arr[2] = cwd, arr[3] = NULL;
	_setenv(arr);
	return (0);
}
