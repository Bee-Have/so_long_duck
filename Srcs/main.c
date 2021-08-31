/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:38:09 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/31 14:37:57 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	main(int ac, char **av)
{
	int		test;
	char	**map;

	if (ac < 2)
		return (error_message("no MAP in param"));
	test = open(av[1], O_RDONLY);
	if (test < 0)
		return (error_message("wrong PATH for MAP"));
	close(test);
	map = NULL;
	test = ft_get_file(av[1], &map);
	if (test == 0 || test == -1 || ft_tablen((const char **)map) == 1)
	{
		ft_freetab(map);
		return (error_message("MAP file is EMPTY"));
	}
	main_manager(map);
	return (0);
}

void	main_manager(char **map)
{
	t_mlx_vars	*mlx;

	mlx = init_mlx_struct();
	init_window(mlx, 0);
	mlx->map->map = map;
	if (map_open_check(map) == -1 || map_chars_check(map) == -1
		|| map_check_mobs(map))
	{
		free_manager(mlx);
		return ;
	}
	find_player(mlx);
	if (mlx_check_size_window(mlx) == 1)
	{
		mlx_destroy_image(mlx->mlx, mlx->img->img);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		init_window(mlx, 0);
	}
	print_moves(0);
	mlx_print_window(mlx);
	free_manager(mlx);
}
