/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:38:09 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/10 18:19:23 by amarini-         ###   ########.fr       */
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
	test = ft_get_file(av[1], &map);
	if (test == 0 || test == -1 || ft_tablen((const char **)map) == 1)
	{
		ft_freetab(map);
		return (error_message("map file is empty"));
	}
	main_manager(map);
}

void	main_manager(char **map)
{
	t_map_info	*map_info;
	t_mlx_vars	*my_mlx;

	ft_print_tab(map);
	map_info = init_map_info();
	map_info->map = map;
	my_mlx = init_mlx_struct();
	if (map_open_check(map) == -1 || map_chars_check(map, my_mlx) == -1)
	{
		free(map_info);
		free(my_mlx);
		ft_freetab(map);
		return ;
	}
	mlx_xpm_file_to_image(my_mlx->mlx, map_info->floor, &map_info->pxl_img, &map_info->pxl_img);
	if (mlx_check_size_window(map_info, my_mlx) == 1)
		init_window(my_mlx);
	mlx_print_window(map_info, my_mlx);
}
