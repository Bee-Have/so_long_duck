/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/11 15:30:51 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	mlx_print_window(t_mlx_vars *mlx)
{
	int		img_width;
	int		img_height;

	mlx_key_hook(mlx->mlx_win, key_hook, &mlx);
	move_pj_map_pos(mlx->map, mlx->map->pj_pos);
	mlx_hook(mlx->mlx_win, 17, 1L<<17, close_window, mlx);
	mlx_loop_hook(mlx->mlx_win,  print_map, mlx);
	mlx_loop(mlx->mlx);
	free(mlx->map);
	free(mlx);
}

int	print_map(t_mlx_vars *mlx)
{
	int		row;
	int		col;
	int		tot_x_pxl;
	int		tot_y_pxl;
	int		x;

	row = 0;
	move_pj_map_pos(mlx->map, mlx->map->pj_pos);
	tot_y_pxl = calc_offset(mlx->map->pxl_img, ft_tablen((const char **)mlx->map->map), mlx->height);
	while (mlx->map->map[row] != NULL)
	{
		col = 0;
		tot_x_pxl = calc_offset(mlx->map->pxl_img, ft_strlen(mlx->map->map[0]), mlx->width);
		while (mlx->map->map[row][col] != '\0')
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx, mlx->textures->floor, &x, &x);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x_pxl, tot_y_pxl);
			if (mlx->map->map[row][col] == '1')
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, get_wall(mlx->map, row, col), &x, &x);
			else
				mlx->img = get_right_xpm(mlx->map->map[row][col], mlx->map);
			if (mlx->img)
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x_pxl, tot_y_pxl);
			tot_x_pxl += mlx->map->pxl_img;
			col++;
		}
		tot_y_pxl += mlx->map->pxl_img;
		row++;
	}
	return (0);
}
