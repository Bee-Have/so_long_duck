/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:51:52 by user42            #+#    #+#             */
/*   Updated: 2021/10/27 17:51:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
