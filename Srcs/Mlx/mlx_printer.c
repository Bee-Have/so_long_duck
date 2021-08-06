/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/06 18:47:28 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	mlx_print_window(t_map_info *map_info, t_mlx_vars *mlx)
{
	int		img_width;
	int		img_height;

	
	print_map(map_info, mlx, map_info->map);
	mlx_loop(mlx->mlx);
}

void	print_map(t_map_info *mapinfo, t_mlx_vars *mlx, char **map)
{
	int		row;
	int		col;
	int		tot_x_pxl;
	int		tot_y_pxl;
	int		x;
	int		y;
	char	*texture;

	row = 0;
	col = 0;
	tot_x_pxl = calc_offset(mapinfo->x_pxl_img, ft_strlen(map[0]), mlx->width, 1);
	tot_y_pxl = calc_offset(mapinfo->y_pxl_img, ft_tablen((const char **)map), mlx->height, mlx->height);
	while (map[row] != NULL)
	{
		while (map[row][col] != '\0')
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx, mapinfo->floor, &x, &y);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x_pxl, tot_y_pxl);
			if (map[row][col] == '1')
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, get_right_wall(mapinfo, row, col), &x, &y);
			else if (map[row][col] == 'C')
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, mapinfo->obj, &x, &y);
			else if (map[row][col] == 'E')
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, mapinfo->exit, &x, &y);
			else if (map[row][col] == 'P')
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, mapinfo->pj, &x, &y);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x_pxl, tot_y_pxl);
			tot_x_pxl += mapinfo->x_pxl_img;
			col++;
		}
		col = 0;
		tot_x_pxl = calc_offset(mapinfo->x_pxl_img, ft_strlen(map[0]), mlx->width, 1);;
		tot_y_pxl += mapinfo->y_pxl_img;
		row++;
	}
}
