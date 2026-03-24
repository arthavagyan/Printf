#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	a;

	a = 10;
	printf("%-10#20d", a);
	return (0);
}
