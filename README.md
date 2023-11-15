# shell_prototype

This is a representation of a simple shell that replicates a linux based shell

## The shell

The shell is a command-line interface that acts as an intermediary between a user and the operating system. Its primary function is to interpret and execute user commands.

## How the shell works

### The following explains the process or steps that a shell goes through

- Displaying the prompt.
	- Reading user input.
	- Parsing the command. (Tokenization)
	- Searching the command. (PATH)
	- Creating a child process. (fork)
- Executing the command. (exec)
	- Wait for the command completetion.
	- Displaying output.
	- Returning to the prompt.
	- Exiting the shell.

## Content of this repository

	- The header file that contains function prototypes.
	- A function that gets the input that the user enters to the prompt.
	- A function that gets the enviroment variables.
	- A function that handles execution of commands along with their arguments.
	- A function that handles the PATH.
	- A function that frees arrays.
	- A main source code file that is an entry point.

## Main Source Code

	```
#include "main.h"

	/**
	 * main - Entry point
	 * @ac: arguments count
	 * @argv: arguments
	 * Return: 0 for success
	 */

int main(int ac, char **argv, char **env)
{
	char *command = NULL, *toks;
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
		if (_strcmp(command, "env") == 0)
		{
			print_environment();
			z = 1;
			continue;
		}
		if (_strcmp(command, "exit") == 0)
		{
			z = 1;
			break;
		}
		z = 0;
		free(command);
		if (z == 0)
			exec_wa(toks, env);
		_free(toks);
	}
	if (command != NULL)
		free(command);
	if (toks != NULL)
		_free(toks);
	return (0);
}

```
