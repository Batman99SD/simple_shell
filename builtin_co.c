#include "main.h"

/**
 * builtin_command - to handle things not exist in shell.
 *
 * @toks: commands to execute.
 * @env: environment.
 *
 * Return: 1 on success, 0 on fail to found comand.
 *
 */
int builtin_command(char **toks, char **env)
{
	if (_strcmp(toks[0], "env") == 0)
	{
		print_environment(env);
		_free(toks);
		return (1);
	}
	else if (_strcmp(toks[0], "exit") == 0)
	{
		_free(toks);
		exit(0);

	}
	_free(toks);

	return (0);
}
