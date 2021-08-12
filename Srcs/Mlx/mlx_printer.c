/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/12 16:59:01 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	test(t_mlx_vars *mlx)
{
	(void)mlx;
	printf("TEST\n");
	return (1);
}

void	mlx_print_window(t_mlx_vars *mlx)
{
	int		img_width;
	int		img_height;

	mlx_hook(mlx->mlx_win, 17, 1L<<17, close_window, mlx);
	mlx_hook(mlx->mlx_win, 2, 1, key_hook, mlx);
	mlx_loop_hook(mlx->mlx, print_map, mlx);
	mlx_loop(mlx->mlx);
	// free(mlx->map);
	// free(mlx);
}

int	print_map(t_mlx_vars *mlx)
{
	int		row;
	int		col;
	int		tot_x_pxl;
	int		tot_y_pxl;
	int		x;
	char	*texture;

	row = 0;
	// mlx->img = mlx_xpm_file_to_image(mlx->mlx, mlx->textures->floor, &x, &x);
	// texture = mlx_get_data_addr(mlx->img, &mlx->bits_pix, &mlx->line_length, &mlx->endian);
	// printf("img-[%s]\n", texture);
	move_pj_map_pos(mlx, mlx->map->pj_pos);
	tot_y_pxl = calc_offset(mlx->map->pxl_img, ft_tablen((const char **)mlx->map->map), mlx->height);
	while (mlx->map->map[row] != NULL)
	{
		col = 0;
		texture = NULL;
		tot_x_pxl = calc_offset(mlx->map->pxl_img, ft_strlen(mlx->map->map[0]), mlx->width);
		while (mlx->map->map[row][col] != '\0')
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx, mlx->textures->floor, &x, &x);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x_pxl, tot_y_pxl);
			texture = get_right_xpm(mlx, row, col);
			if (texture != NULL)
			{
				mlx->img = mlx_xpm_file_to_image(mlx->mlx, texture, &x, &x);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x_pxl, tot_y_pxl);
			}
			tot_x_pxl += mlx->map->pxl_img;
			col++;
		}
		tot_y_pxl += mlx->map->pxl_img;
		row++;
	}
	return (1);
}
