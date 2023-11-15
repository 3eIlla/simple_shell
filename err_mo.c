#include "shell.h"



/**
 * error_env -  error message 4 shellby_env.
 *
 * @args: arr o argms 2 z command.
 *
 * Return: str_error .
 */
char *error_env(char **args)
{
	int len;
	char *error;
	char *hist_str;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	args--;
	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 45;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": Unable to add/remove from environment\n");

	free(hist_str);
	return (error);
}

/**
 * error_1 -  error message 4 alias.
 *
 * @args: arr o argms 2 z command.
 *
 * Return: str_error
 */
char *error_1(char **args)
{
	int len;
	char *error;

	len = _strlen(name) + _strlen(args[0]) + 13;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
		return (NULL);

	_strcpy(error, "alias: ");
	_strcat(error, args[0]);
	_strcat(error, " not found\n");

	return (error);
}

/**
 * error_2_exit -  error message 4 exit.
 *
 * @args: arr o argms 2 z command.
 *
 * Return: str_error
 */
char *error_2_exit(char **args)
{
	int len;
	char *error;
	char *hist_str;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 27;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": exit: Illegal number: ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * error_2_cd -  error message 4 cd
 *
 * @args: arr o argms 2 z command.
 *
 * Return: str_error
 */
char *error_2_cd(char **args)
{
	int len;
	char *error;
	char *hist_str;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;

	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);

	if (args[0][0] == '-')
		_strcat(error, ": cd: Illegal option ");
	else
		_strcat(error, ": cd: can't cd to ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * error_2_syntax -  error message 4 syntax.
 *
 * @args: arr o argms 2 z command.
 *
 * Return: str_error
 */
char *error_2_syntax(char **args)
{
	int len;
	char *error;
	char *hist_str;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);
	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 33;


	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": Syntax error: \"");
	_strcat(error, args[0]);
	_strcat(error, "\" unexpected\n");

	free(hist_str);

	return (error);
}
