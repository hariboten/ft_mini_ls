#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int		main()
{
	struct stat tmp;

	printf("%d\n", stat("a.out", &tmp));
}
