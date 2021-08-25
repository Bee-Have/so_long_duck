/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:38:09 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/25 19:04:04 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	main(int ac, char **av)
{
	int		test;
	char	**map;

	if (ac < 2)
		return (error_message("no map in param"));
	test = open(av[1], O_RDONLY);
	if (test < 0)
		return (error_message("wrong path for map"));
	close(test);
	map = NULL;
	test = ft_get_file(av[1], &map);
	if (test == 0 || test == -1 || ft_tablen((const char **)map) == 1)
	{
		ft_freetab(map);
		return (error_message("map file is empty"));
	}
	main_manager(map);
	return (0);
}

void	main_manager(char **map)
{
	t_mlx_vars	*mlx;

	mlx = init_mlx_struct();
	init_window(mlx);
	mlx->map->map = map;
	if (map_open_check(map) == -1 || map_chars_check(map, mlx) == -1)
	{
		free_manager(mlx);
		return ;
	}
	if (mlx_check_size_window(mlx) == 1)
	{
		mlx_destroy_image(mlx->mlx, mlx->img->img);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		init_window(mlx);
	}
	find_player(mlx);
	find_mobs(mlx);
	mlx_print_window(mlx);
	ft_freetab(map);
}
