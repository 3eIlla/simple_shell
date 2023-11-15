#include "shell.h"



/**
 * add_alias_end - Add n.node 2 end o alias_t linked list.
 *
 * @head: A pointer to the head of the list_t list.
 * @name: The name of the new alias to be added.
 * @value: The value of the new alias to be added.
 *
 * Return: f err occurs (NULL).
 *         Otherwise (pointer 2 n.node).
 */
alias_t *add_alias_end(alias_t **head, char *name, char *value)
{
	alias_t *new_node = malloc(sizeof(alias_t));
	alias_t *last;

	while (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));

	if (!new_node->name)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	_strcpy(new_node->name, name);

	if (*head)
	{
		last = *head;
		if (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * add_node_end - Add n.node 2 end o list_t linked list.
 *
 * @head: pointer 2 z head of z list_t list.
 * @dir: directory path 4 n.node 2 contain.
 *
 * Return: f err occurs  (NULL).
 *         Otherwise  (pointer 2 n.node).
 */
list_t *add_node_end(list_t **head, char *dir)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *last;

	while (!new_node)
		return (NULL);
	new_node->dir = dir;
	new_node->next = NULL;

	if (*head)
	{
		last = *head;
		if (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}


/**
 * get_args - Gets a command from standard input.
 *
 * @line: buffer 2 store z command.
 * @exe_ret:  value o z last executed command.
 *
 * Return: If an error occurs  (NULL).
 *         Otherwise  (pointer to the stored command).
 */
char *get_args(char *line, int *exe_ret)
{
	size_t nl = 0;
	ssize_t read;
	char *prompt = "$ ";

	if (line)
		free(line);

	read = _getline(&line, &nl, STDIN_FILENO);
	if (read == -1)
		return (NULL);
	if (read == 1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 2);
		return (get_args(line, exe_ret));
	}

	line[read - 1] = '\0';
	variable_replacement(&line, exe_ret);
	handle_line(&line, read);

	return (line);
}


/**
 * _getenv - Get environ variable from PATH.
 *
 * @var: name o  environ variable 2 get.
 *
 * Return:  (NULL) f environ variable doesn't exist .
 *         Otherwise (pntr 2 environ variable).
 */
char **_getenv(const char *var)
{
	int ndx, len;

	len = _strlen(var);
	for (ndx = 0; environ[ndx]; ndx++)
	{
		if (_strncmp(var, environ[ndx], len) == 0)
			return (&environ[ndx]);
	}

	return (NULL);
}
