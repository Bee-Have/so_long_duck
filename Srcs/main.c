/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:38:09 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/23 20:34:44 by user42           ###   ########.fr       */
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
	
	mlx_xpm_file_to_image(mlx->mlx, mlx->ref->tile->img, &mlx->map->pxl_img,
		&mlx->map->pxl_img);
	if (mlx_check_size_window(mlx) == 1)
		init_window(mlx);
	find_player(mlx);
	mlx_print_window(mlx);
	ft_freetab(map);
}
