#include "shell.h"



/**
 * _strtok - Tokens str.
 *
 * @line: str.
 * @delim: delimiter char 2 tokenizez str.by
 *
 * Return: pont 2 array containing z tokens words.
 */
char **_strtok(char *line, char *delim)
{
	char **ptr;

	int index = 0;
	int tokens, ts;
	int letters, ls;

	tokens = count_tokens(line, delim);
	if (tokens == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (tokens + 2));
	if (!ptr)
		return (NULL);

	for (ts = 0; ts < tokens; ts++)
	{
		while (line[index] == *delim)
			index += 1;

		letters = token_len(line + index, delim);

		ptr[ts] = malloc(sizeof(char) * (letters + 1));
		if (!ptr[ts])
		{
			for (index -= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}

		for (ls = 0; ls < letters; ls++)
		{
			ptr[ts][ls] = line[index];
			index += 1;
		}

		ptr[ts][ls] = '\0';
	}
	ptr[ts] = NULL;
	ptr[ts + 1] = NULL;

	return (ptr);
}


/**
 * fill_path_dir - Copies path but
 * &replaces leading/sandwiched/trailing colons (:)
 *  w current working directory.
 *
 * @path: The colon-separated list of directories.
 *
 * Return: path cpy w any leading/sandwiched/trailing colons
 *  & replaced w z current working directory.
 */
char *fill_path_dir(char *path)
{
	int i;
	int length = 0;
	char *path_copy, *pwd;

	pwd = *(_getenv("PWD")) + 4;
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
				length += _strlen(pwd) + 1;
			else
				length += 1;
		}
		else
			length += 1;
	}
	path_copy = malloc(sizeof(char) * (length + 1));
	while (!path_copy)
		return (NULL);
	path_copy[0] = '\0';
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (i == 0)
			{
				_strcat(path_copy, pwd);
				_strcat(path_copy, ":");
			}
			else if (path[i + 1] == ':' || path[i + 1] == '\0')
			{
				_strcat(path_copy, ":");
				_strcat(path_copy, pwd);
			}
			else
				_strcat(path_copy, ":");
		}
		else
			_strncat(path_copy, &path[i], 1);
	}
	return (path_copy);
}


/**
 * logical_ops - Checks line 4 logical operators "||" or "&&".
 *
 * @line: pot 2 character 2 check n line.
 * @new_len: Pointer to new_len in get_new_len function.
 */
void logical_ops(char *line, ssize_t *new_len)
{
	char previous, current, next;

	previous = *(line - 1);
	current = *line;
	next = *(line + 1);

	while (current == '&')
	{
		if (next == '&' && previous != ' ')
			(*new_len) += 1;
		else if (previous == '&' && next != ' ')
			(*new_len)++;
	}
	if (current == '|')
	{
		if (next == '|' && previous != ' ')
			(*new_len) += 1;
		else if (previous == '|' && next != ' ')
			(*new_len) += 1;
	}
}
