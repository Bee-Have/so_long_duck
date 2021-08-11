/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/11 11:51:15 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	mlx_print_window(t_map_info *map_info, t_mlx_vars *mlx)
{
	int		img_width;
	int		img_height;

	mlx_key_hook(mlx->mlx_win, key_hook, &mlx);
	move_pj_map_pos(map_info, mlx->pj_pos);
	// ft_print_tab(map_info->map);
	mlx_hook(mlx->mlx_win, 17, 1L<<17, close_window, mlx);
	mlx_loop_hook(mlx->mlx_win,  print_map, map_info, mlx);
	// print_map(map_info, mlx, map_info->map);
	mlx_loop(mlx->mlx);
	free(map_info);
	free(mlx);
}

int	print_map(t_map_info *map, t_mlx_vars *mlx)
{
	int		row;
	int		col;
	int		tot_x_pxl;
	int		tot_y_pxl;
	int		x;

	row = 0;
	move_pj_map_pos(map, mlx->pj_pos);
	tot_y_pxl = calc_offset(map->pxl_img, ft_tablen((const char **)map->map), mlx->height);
	while (map->map[row] != NULL)
	{
		col = 0;
		tot_x_pxl = calc_offset(map->pxl_img, ft_strlen(map->map[0]), mlx->width);
		while (map->map[row][col] != '\0')
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx, map->floor, &x, &x);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x_pxl, tot_y_pxl);
			if (map->map[row][col] == '1')
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, get_wall(map, row, col), &x, &x);
			else
				mlx->img = get_right_xpm(map->map[row][col], map);
			if (mlx->img)
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x_pxl, tot_y_pxl);
			tot_x_pxl += map->pxl_img;
			col++;
		}
		tot_y_pxl += map->pxl_img;
		row++;
	}
	return (0);
}
