/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/20 14:29:52 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	mlx_print_window(t_mlx_vars *mlx)
{
	int		img_width;
	int		img_height;

	mlx->map->pj_moved = 0;
	find_player(mlx);
	mlx_loop_hook(mlx->mlx, print_all, mlx);
	mlx_hook(mlx->mlx_win, 17, 1L<<17, close_window, mlx);
	mlx_hook(mlx->mlx_win, 2, 1, key_hook, mlx);
	mlx_loop(mlx->mlx);
}

int	print_all(t_mlx_vars *mlx)
{
	int		txt_x;
	int		txt_y;
	char	*moves;

	if (mlx->map->pj_moved > 0)
		move_pj_map_pos(mlx, mlx->map->pj_pos);
	find_player(mlx);
	print_map(mlx, 1);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
	print_map(mlx, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
	txt_x = mlx->img->width / 2;
	txt_y = offset(mlx->map->pxl_img,
			ft_tablen((const char **)mlx->map->map) + 1, mlx->img->height);
	moves = ft_itoa(mlx->map->moves);
	mlx_string_put(mlx->mlx, mlx->mlx_win, txt_x, txt_y, 0x00F8FFFA, moves);
	free(moves);
	return (1);
}

void	print_map(t_mlx_vars *mlx, int floor)
{
	int		row;
	int		col;
	int		tot_x;
	int		tot_y;

	row = 0;
	tot_y = offset(mlx->map->pxl_img,
			ft_tablen((const char **)mlx->map->map), mlx->img->height);
	while (mlx->map->map[row] != NULL)
	{
		col = 0;
		tot_x = offset(mlx->map->pxl_img,
				ft_strlen(mlx->map->map[0]), mlx->img->width);
		while (mlx->map->map[row][col] != '\0')
		{
			if (floor == 1)
				add_img(mlx, get_anim(&mlx->ref->tile, 150), tot_x * 4, tot_y);
			else if (floor == 0 && mlx->map->map[row][col] != '0')
				add_img(mlx, get_right_xpm(mlx, row, col), tot_x * 4, tot_y);
			tot_x += mlx->map->pxl_img;
			col++;
		}
		tot_y += mlx->map->pxl_img;
		row++;
	}
}

void	add_img(t_mlx_vars *mlx, char *path, int tot_x, int tot_y)
{
	t_img	*tmp;
	int		i;
	int		size;
	int		j;

	i = 0;
	tmp = init_img();
	tmp->img = mlx_xpm_file_to_image(mlx->mlx, path, &size, &size);
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bits_pxl,
			&tmp->line_len, &tmp->endian);
	size = tmp->line_len * 36;
	black_to_transparency(tmp->addr, size);
	while (i < size)
	{
		j = 0;
		while (j < tmp->line_len)
		{
			mlx->img->addr[(tot_y * mlx->img->line_len) + tot_x + j]
				= tmp->addr[i];
			++j;
			++i;
		}
		++tot_y;
	}
	// mlx_destroy_image(mlx->mlx, tmp);
	free(tmp);
}
