/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/17 12:23:50 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

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
	int		tot_x;
	int		tot_y;

	row = 0;
	tot_y = calc_offset(mlx->map->pxl_img, ft_tablen((const char **)mlx->map->map), mlx->img->height);
	if (mlx->map->pj_moved == 1)
		move_pj_map_pos(mlx, mlx->map->pj_pos);
	while (mlx->map->map[row] != NULL)
	{
		col = 0;
		tot_x = calc_offset(mlx->map->pxl_img, ft_strlen(mlx->map->map[0]), mlx->img->width);
		while (mlx->map->map[row][col] != '\0')
		{
			sprite_to_img(mlx, mlx->textures->floor, tot_x, tot_y);
			tot_x += mlx->map->pxl_img;
			col++;
		}
		tot_y += mlx->map->pxl_img;
		row++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
	print_sprites(mlx);
	return (1);
}

int	print_sprites(t_mlx_vars *mlx)
{
	int		row;
	int		col;
	int		tot_x;
	int		tot_y;

	row = 0;
	tot_y = calc_offset(mlx->map->pxl_img, ft_tablen((const char **)mlx->map->map), mlx->img->height);
	while (mlx->map->map[row] != NULL)
	{
		col = 0;
		tot_x = calc_offset(mlx->map->pxl_img, ft_strlen(mlx->map->map[0]), mlx->img->width);
		while (mlx->map->map[row][col] != '\0')
		{
			if (get_right_xpm(mlx, row, col))
				sprite_to_img(mlx, get_right_xpm(mlx, row, col), tot_x, tot_y);
			tot_x += mlx->map->pxl_img;
			col++;
		}
		tot_y += mlx->map->pxl_img;
		row++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
	return (1);
}

void	sprite_to_img(t_mlx_vars *mlx, char *path, int tot_x, int tot_y)
{
	t_img	*tmp_img;
	int		x;
	int		i;
	int		size;
	int		j;

	i = 0;
	tmp_img = init_img();
	tmp_img->img = mlx_xpm_file_to_image(mlx->mlx, path, &x, &x);
	tmp_img->addr = mlx_get_data_addr(tmp_img->img, &tmp_img->bits_pxl,
				&tmp_img->line_length, &tmp_img->endian);
	size = tmp_img->line_length * 36;
	black_to_transparency(tmp_img->addr, size);
	tot_x *= 4;
	while (i < size)
	{
		j = 0;
		while (j < tmp_img->line_length)
		{
			mlx->img->addr[(tot_y * mlx->img->line_length) + tot_x + j] = tmp_img->addr[i];
			++j;
			++i;
		}
		++tot_y;
	}
	free(tmp_img);
}
