/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/10 18:54:09 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	mlx_print_window(t_map_info *map_info, t_mlx_vars *mlx)
{
	int		img_width;
	int		img_height;

	print_map(map_info, mlx, map_info->map);
	mlx_key_hook(mlx->mlx_win, key_hook, &mlx);
	move_pj_map_pos(map_info, mlx->pj_pos);
	ft_print_tab(map_info->map);
	mlx_hook(mlx->mlx_win, 17, 1L<<17, close_window, mlx);
	mlx_loop(mlx->mlx);
	free(map_info);
	free(mlx);
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
	tot_x_pxl = calc_offset(mapinfo->pxl_img, ft_strlen(map[0]), mlx->width);
	tot_y_pxl = calc_offset(mapinfo->pxl_img, ft_tablen((const char **)map), mlx->height);
	while (map[row] != NULL)
	{
		while (map[row][col] != '\0')
		{
			texture = NULL;
			mlx->img = mlx_xpm_file_to_image(mlx->mlx, mapinfo->floor, &x, &y);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x_pxl, tot_y_pxl);
			if (map[row][col] == '1')
				texture = get_right_wall(mapinfo, row, col);
			else if (map[row][col] == 'C')
				texture = mapinfo->obj;
			else if (map[row][col] == 'E')
				texture = mapinfo->exit;
			else if (map[row][col] == 'P')
				texture = mapinfo->pj;
			mlx->img = mlx_xpm_file_to_image(mlx->mlx, texture, &x, &y);
			if (mlx->img)
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x_pxl, tot_y_pxl);
			tot_x_pxl += mapinfo->pxl_img;
			col++;
		}
		col = 0;
		tot_x_pxl = calc_offset(mapinfo->pxl_img, ft_strlen(map[0]), mlx->width);
		tot_y_pxl += mapinfo->pxl_img;
		row++;
	}
}
