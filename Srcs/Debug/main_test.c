#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval	old;
	struct timeval	current;
	long int		test;

	gettimeofday(&old, NULL);
	current = old;

	//ok so, we want to switch animation every x seconds
	//said seconds will be given in the struct of the anim
	//time in anim will be timeval struct (old)

	while (1)
	{
		test = ((current.tv_sec - old.tv_sec) * 1000)
			+ ((current.tv_usec - old.tv_usec) / 1000);
		if (test >= 70)
		{
			printf("[%ld]\n", test);
			old = current;
		}
		gettimeofday(&current, NULL);
	}
}
