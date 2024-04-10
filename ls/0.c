#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/**
 * main - 0. Let's start with something simple!
 * @path: path
 *
 * Return: Alwais 0 (Success)
 */

void list_directory(const char *path)
{
	DIR *dir;
	struct dirent *entry;

	/*Open current directory*/
	dir = opendir(path);
	if (dir == NULL)
	{
		fprintf(stderr, "%s: %s %s: %s\n", "./hls", "cannot access"
		, path, strerror(errno));
		exit(EXIT_FAILURE);
	}

	/*Read directory entries*/
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
			printf("%s  ", entry->d_name);
	}
	printf("\n");

	/*Close directory*/
	closedir(dir);
}

/**
 * main - 1. Maybe some parameters?
 * @argc: counter
 * @argv: vector
 *
 * Return: Alwais 0 (Success)
 */

int main(int argc, char *argv[])
{
	int i;

	/* If no arguments provided, list current directory */
	if (argc == 1)
	{
		list_directory("./");
	} else
	{
		/* Iterate through command-line arguments */
		for (i = 1; i < argc; i++)
		{
			printf("%s:\n", argv[i]);
			list_directory(argv[i]);
			/*loop for counter an argc: if c == counter so printf*/
			if (argc > 2)
			{
				printf("\n");
			}
		}
	}
	return (0);
}
