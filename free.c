#include "main.h"
/**
 * _free - free the allocated memory.
 * @arr: array to be freed.
 * Return: void.
 */

void _free(char **arr)
{
	int i;

	if (arr == NULL)
		return;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
