/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/23 12:52:51 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_print_window(t_mlx_vars *mlx)
{
	mlx->gp.pj.pj_moved = 0;
	find_player(mlx);
	mlx_loop_hook(mlx->mlx, print_all, mlx);
	mlx_hook(mlx->mlx_win, 17, 1L << 17, close_window, mlx);
	mlx_hook(mlx->mlx_win, 2, 1, key_hook, mlx);
	mlx_loop(mlx->mlx);
}

int	print_all(t_mlx_vars *mlx)
{
	move_mob_manager(mlx);
	update_exits(mlx);
	if (mlx->gp.pj.pj_moved > 0)
	{
		mlx->gp.pj.pj_moved = 0;
		if (mlx->map[mlx->gp.pj.pj_pos[0]][mlx->gp.pj.pj_pos[1]] == 'C')
		{
			// mlx->map->c_pos[i]->x;
			--mlx->gp.c_count;
		}
		move_pj_map_pos(mlx, mlx->gp.pj.pj_pos);
	}
	find_player(mlx);
	ft_memset(mlx->img.addr, 0, (mlx->img.width * mlx->img.height) * 4);
	print_map(mlx, 1);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	print_map(mlx, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	if (mlx->gp.mobs_count > 0)
		print_manager(mlx);
	return (1);
}

void	print_map(t_mlx_vars *mlx, int floor)
{
	int		row;
	int		col;
	int		tot_x;
	int		tot_y;

	row = 0;
	tot_y = offset(mlx->pxl_img,
			ft_tablen((const char **)mlx->map), mlx->img.height);
	while (mlx->map[row] != NULL)
	{
		col = 0;
		tot_x = offset(mlx->pxl_img, ft_strlen(mlx->map[0]), mlx->img.width);
		while (mlx->map[row][col] != '\0')
		{
			if (floor == 1)
				add_img(mlx, get_anim(&mlx->ref.tile, 800), tot_x * 4, tot_y);
			else if (floor == 0 && mlx->map[row][col] != '0')
				add_img(mlx, get_right_xpm(mlx, row, col), tot_x * 4, tot_y);
			tot_x += mlx->pxl_img;
			col++;
		}
		tot_y += mlx->pxl_img;
		row++;
	}
}

void	add_img(t_mlx_vars *mlx, t_img sprite, int tot_x, int tot_y)
{
	int		i;
	int		size;
	int		j;

	i = 0;
	size = sprite.line_len * 36;
	while (i < size)
	{
		j = 0;
		while (j < sprite.line_len)
		{
			if (sprite.addr[i] != 0x00)
			{
				mlx->img.addr[(tot_y * mlx->img.line_len) + tot_x + j]
					= sprite.addr[i];
			}
			++j;
			++i;
		}
		++tot_y;
	}
}
