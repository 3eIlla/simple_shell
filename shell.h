#ifndef _SHELL_H_
#define _SHELL_H_


/*###############################################################*/




/*Libraries*/

#include <stdio.h>    /*For any out in puts */

#include <unistd.h>  /*for display the function write */

#include <stdarg.h>   /*For  */

#include <stdarg.h>   /*for argument after "..."*/

#include <limits.h>   /*for max byet no. */

#include <stdlib.h>    /*For  */

#include <string.h>    /*For  */

#include <errno.h>    /*For  */

#include <fcntl.h>    /*For  */

#include <signal.h>   /*For  */

#include <sys/types.h>   /*For  */

#include <sys/wait.h>    /*For  */

#include <sys/stat.h>    /*For  */






/*###############################################################*/


/*               new defs            */



#define END_OF_FILE -2
#define EXIT -3




/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;





/*###############################################################*/


/* globals */


/* Global environemnt */
extern char **environ;

/* Global program name */
char *name;

/* Global history counter */
int hist;

/* Global aliases linked list */
alias_t *aliases;

/*###############################################################*/

/**/


/*_main.c*/
void sig_handler(int sig);
int execute(char **args, char **front);
int main(int argc, char *argv[]);


/*err_std.c*/
int num_len(int num);
char *_itoa(int num);
int create_error(char **args, int err);
char *error_126(char **args);
char *error_127(char **args);



/*err_mo.c*/
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);



/*to_help1.c*/
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);

/*to_help2.c*/
void help_help(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);




/*shellby_builtin.c*/
int shellby_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_help(char **args, char __attribute__((__unused__)) **front);
int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);



/*shellbys_builtin.c*/
int shellby_alias(char **args, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
int (*get_builtin(char *command))(char **args, char **front);
int shellby_exit(char **args, char **front);


/*shellbys_builtins.c*/
void variable_replacement(char **args, int *exe_ret);
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_copyenv(void);
char **replace_aliases(char **args);






/*inputs.c*/
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);



/*gets.c*/
list_t *get_path_dir(char *path);
char *get_location(char *command);
ssize_t get_new_len(char *line);
char *get_pid(void);
char *get_env_value(char *beginning, int len);



/*voint.c*/
int cant_open(char *file_path);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/*voinch.c*/
void handle_line(char **line, ssize_t read);
int proc_file_commands(char *file_path, int *exe_ret);

/*vochar.c*/
char **_strtok(char *line, char *delim);
char *fill_path_dir(char *path);
void logical_ops(char *line, ssize_t *new_len);






/*str_to_add.c*/
alias_t *add_alias_end(alias_t **head, char *name, char *value);
list_t *add_node_end(list_t **head, char *dir);
char *get_args(char *line, int *exe_ret);
char **_getenv(const char *var);



/*str_to_free.c*/
void free_alias_list(alias_t *head);
void free_list(list_t *head);
void free_args(char **args, char **front);
void free_env(void);




/*str_chars.c*/
char *_strchr(char *s, char c);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);


/*str_ints.c*/
int _strlen(const char *s);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);




/*###############################################################*/




/*###############################################################*/








#endif /* _SHELL_H_ */
