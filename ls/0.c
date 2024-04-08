#include <stdio.h>
#include <dirent.h>

/**
 * main - 0. Let's start with something simple!
 * @void: that lists the content of the current directory.
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
