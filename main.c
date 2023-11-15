#include "main.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @argv: arguments
 * @env: environment.
 * Return: 0 for success
 */

int main(int ac, char **argv, char **env)
{
	char *command = NULL, **toks;
	int z = 0;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);

		command = get_line(argv);
		if (command == NULL)
			continue;

		toks = tok(command);
		if (toks == NULL)
		{
			free(command);
			continue;
		}
		if ((_strcmp(command, "env") == 0) || (_strcmp(command, "exit") == 0))
		{
			builtin_command(toks, env);
			z = 1;
			continue;
		}
		z = 0;
		free(command);
		if (z == 0)
			exec_wa(toks[0], toks, env);
		_free(toks);
	}
	if (command != NULL)
		free(command);
	if (toks != NULL)
		_free(toks);
	return (0);
}
