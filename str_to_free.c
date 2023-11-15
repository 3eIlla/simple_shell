#include "shell.h"



/**
 * free_alias_list - Free alias_t list.
 *
 * @head: head o list_t lst.
 */
void free_alias_list(alias_t *head)
{
	alias_t *next;

	if (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}

/**
 * free_list - Free list_t lst.
 *
 * @head: head o list_t lst.
 */
void free_list(list_t *head)
{
	list_t *next;

	if (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}


/**
 * free_args - Free args memo .
 *
 * @args: null-termn double pontr contain commands/args.
 * @front: double pontr 2 z bgnn o args.
 */
void free_args(char **args, char **front)
{
	size_t lil;

	for (lil = 0; args[lil] || args[lil + 1]; lil++)
		free(args[lil]);

	free(front);
}


/**
 * free_env - Free z environ cpy.
 */
void free_env(void)
{
	int ndx;

	for (ndx = 0; environ[ndx]; ndx++)
		free(environ[ndx]);
	free(environ);
}
