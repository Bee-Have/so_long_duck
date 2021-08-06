/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:38:09 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/06 12:22:11 by amarini-         ###   ########.fr       */
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
	if (test == 0 || test == -1 || ft_tablen((const char **)map) == 1)
	{
		//if return of readfile is bad return ERROR
		ft_freetab(map);
		return (error_message("map file is empty"));
	}
	//check if map is correct
	if (map_check(map) == -1)
		return (0);
	//sent rest to global manager
	main_manager(map);
}

void	main_manager(char **map_good)
{
	t_map_info	*map_info;
	t_mlx_vars	*my_mlx;

	ft_print_tab(map_good);
	//setup struct with map && textures
	map_info = init_map_info();
	map_info->map = map_good;
	//init mlx
	my_mlx = init_window();
	//send both structs to the screen printer
	mlx_xpm_file_to_image(my_mlx->mlx, map_info->floor, &map_info->x_pxl_img, &map_info->y_pxl_img);
	mlx_print_window(map_info, my_mlx);
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
			if ((map[row][col] == '0' || map[row][col] == 'C'
				|| map[row][col] == 'E' || map[row][col] == 'P')
				&& (col == 0 || col == ft_strlen((const char *)map[row])
				|| row == 0 || row == ft_tablen((const char **)map)))
			{
				ft_freetab(map);
				return (error_message("map is not closed"));
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}
