/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:38:09 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/04 15:17:41 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	main(int ac, char **av)
{
	int		test;
	char	**map;

	//check if params are good
		//if not return ERROR
	if (ac < 2)
		return (error_message("no map in param"));
	//open fd with path && check if correct path
	test = open(av[1], O_RDONLY);
	if (test < 0)
		return (error_message("wrong path for map"));
	close(test);
	//read file
	test = ft_get_file(av[1], &map);
	if (test == 0 || test == -1)
	{
		//if return of readfile is bad return ERROR
		ft_freetab(map);
		return (error_message("map file is empty"));
	}
	//check if map is correct
	if (map_check(map) == -1)
	{
		ft_freetab(map);
		return (0);
	}
	//sent rest to global manager
	main_manager(map);
}

void	main_manager(char **map)
{
	printf("SUCCESS\n");
	ft_print_tab(map);
}

int		map_check(char **map)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (map[row] != NULL)
	{
		while (map[row][col] != '\0')
		{
			if (map[row][col] == '1'
				&& (map[row][col--] < 0 || map[row][col++] == '\0'
				|| row++ < 0 || map[row--] == NULL))
				return (error_message("map is not closed"));
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}
