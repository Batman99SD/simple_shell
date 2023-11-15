#include "main.h"
/**
 * exe_wa - execute the command.
 * @path: file path.
 * @argv: argument valeu.
 * @env: system environment.
 *Return: void.
 */
void exec_wa(char *path, char *const *argv, char **env)
{
	pid_t pid;
	int status;
	if (path == NULL)
	{
		return;
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
		}
		else if (pid == 0)
		{

			if (execve(path, argv, env) == -1)
			{
				perror("execve Error");
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}    
}
