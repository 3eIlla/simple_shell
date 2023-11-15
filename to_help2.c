#include "shell.h"


/**
 * help_help - shellby builtin command info 'help'.
 */
void help_help(void)
{
	char *msg = "help: help\n\tSee all possible Shellby builtin commands.\n";

write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";

write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "builtin command.\n";

write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_env - shellby builtin command info 'env'.
 */
void help_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_setenv - shellby builtin command info 'setenv'.
 */
void help_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environment variable, or modifies an existing one.\n\n";

write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";

write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_unsetenv - shellby builtin command
 * 'unsetenv'.
 */
void help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";

write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";

write(STDOUT_FILENO, msg, _strlen(msg));
}
