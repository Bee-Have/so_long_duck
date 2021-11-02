/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/11/02 17:39:36 by amarini-         ###   ########.fr       */
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
	if (mlx->gp.mobs_count != NOT_BONUS)
		gettimeofday(&mlx->time, NULL);
	move_mob_manager(mlx);
	update_objs(mlx);
	if (mlx->gp.pj.pj_moved > 0)
	{
		mlx->gp.pj.pj_moved = 0;
		if (mlx->map[mlx->gp.pj.pj_pos.y][mlx->gp.pj.pj_pos.x] == 'C')
			delete_collectible(mlx, mlx->gp.pj.pj_pos);
		move_pj_map_pos(mlx, mlx->gp.pj.pj_pos);
	}
	find_player(mlx);
	ft_memset(mlx->img.addr, 0, (mlx->img.width * mlx->img.height) * 4);
	print_map(mlx, PRINT_FLOOR);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	print_map(mlx, PRINT_REST);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	if (mlx->gp.mobs_count > NOT_BONUS)
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
			if (floor == PRINT_FLOOR)
				add_img(mlx, get_anim(&mlx->ref.tile, ANIM_TILE, mlx->time),
					tot_x * 4, tot_y);
			else if (floor == PRINT_REST && mlx->map[row][col] != '0')
				add_img(mlx, get_right_xpm(mlx, row, col), tot_x * 4, tot_y);
			tot_x += mlx->pxl_img;
			col++;
		}
		tot_y += mlx->pxl_img;
		row++;
	}
}

/*
** Here, pos[0] = the position inside the sprite
** Here, pos[1] = the position inside the window image (in which we are copying)
*/
void	add_img(t_mlx_vars *mlx, t_img sprite, int tot_x, int tot_y)
{
	t_vec2	pos[2];

	set_vec2(&pos[0], 0);
	while (pos[0].y < (sprite.line_len * 36))
	{
		set_vec2(&pos[1], 0);
		if (sprite.rev_print == 1)
			pos[0].x = sprite.line_len - 4;
		while (pos[1].y < sprite.line_len)
		{
			if (sprite.addr[pos[0].y + pos[0].x + pos[1].x] != 0x00)
				mlx->img.addr[(tot_y * mlx->img.line_len) + tot_x + pos[1].y]
					= sprite.addr[pos[0].y + pos[0].x + pos[1].x];
			if (sprite.rev_print == 1 && pos[1].x == 3)
			{
				pos[0].x -= 4;
				pos[1].x = 0;
			}
			else
				++pos[1].x;
			++pos[1].y;
		}
		pos[0].y += sprite.line_len;
		++tot_y;
	}
}
