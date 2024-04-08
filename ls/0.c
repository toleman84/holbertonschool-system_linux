#include <stdio.h>
#include <dirent.h>

int main(void)
{
	DIR *dir;
	struct dirent *entry;

	/*Open current directory*/
	dir = opendir("./");
	if (dir == NULL)
	{
		perror("Unable to open directory");
		return (1);
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

	return (0);
}
