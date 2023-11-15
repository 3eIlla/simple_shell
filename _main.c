#include "shell.h"


/**
 * sig_handler - Prints  n.prompt upon signal.
 *
 * @sig: signal.
 */
void sig_handler(int sig)
{
	char *new_prompt = "\n$ ";

	(void)sig;

signal(SIGINT, sig_handler);

write(STDIN_FILENO, new_prompt, 3);
}

/**
 * execute - Executes command n child process.
 *
 * @args: arr o argms.
 * @front: double pontr 2 z begnn o args.
 *
 * Return: f err occurs (corresponding error code).
 *         (O/w) exit value o z last executed command.
 */
int execute(char **args, char **front)
{
	pid_t child_pid;
	char *command = args[0];

	int status;
	int flag = 0;
	int ret = 0;
	

	while (command[0] != '/' && command[0] != '.')
	{
		flag = 1;
		command = get_location(command);
	}

	if (!command || (access(command, F_OK) == -1))
	{
		if (errno == EACCES)
			ret = (create_error(args, 126));
		else
			ret = (create_error(args, 127));
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			if (flag)
				free(command);
			perror("Error child:");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(command, args, environ);
			if (errno == EACCES)
				ret = (create_error(args, 126));
			free_env();
			free_args(args, front);
			free_alias_list(aliases);
			_exit(ret);
		}
		else
		{
			wait(&status);
			ret = WEXITSTATUS(status);
		}
	}
	if (flag)
		free(command);
	return (ret);
}

/**
 * main - Run simple UNIX command int.
 *
 * @argc: no o argms supplied 2 z program.
 * @argv: arr o pontrs 2 z argms.
 *
 * Return: value o z last executed command.
 */
int main(int argc, char *argv[])
{
	int retn;
	int ret = 0;
	int *exe_ret = &retn;

	char *prompt = "$ ";
	char *new_line = "\n";

	name = argv[0];
	hist = 1;
	aliases = NULL;

signal(SIGINT, sig_handler);

	*exe_ret = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);

	while (argc != 1)
	{
		ret = proc_file_commands(argv[1], exe_ret);
		free_env();
		free_alias_list(aliases);
		return (*exe_ret);
	}

	if (!isatty(STDIN_FILENO))
	{
		while (ret != END_OF_FILE && ret != EXIT)
			ret = handle_args(exe_ret);
		free_env();
		free_alias_list(aliases);
		return (*exe_ret);
	}

	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		ret = handle_args(exe_ret);
		if (ret == END_OF_FILE || ret == EXIT)
		{
			if (ret == END_OF_FILE)
				write(STDOUT_FILENO, new_line, 1);
			free_env();
			free_alias_list(aliases);
			exit(*exe_ret);
		}
	}

	free_env();
	free_alias_list(aliases);
	return (*exe_ret);
}
