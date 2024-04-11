#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/**
 * main - 1. Maybe some parameters?
 *
 * Return: Alwais 0 (Success)
 */

int main(void)
{
	DIR *dir;
	struct dirent *entry;

	/*Open current directory*/
	dir = opendir("./");

	/*Read directory entries*/
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
			printf("%s  ", entry->d_name);
	}
	printf("\n");

	/*Close directory*/
	closedir(dir);

	return (0);
}
