/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/11/02 20:51:52 by user42           ###   ########.fr       */
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
	print_map(mlx, PRINT_1CE);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	print_map(mlx, PRINT_PM);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	if (mlx->gp.mobs_count > NOT_BONUS)
		print_manager(mlx);
	return (1);
}

void	print_map(t_mlx_vars *mlx, int print)
{
	t_vec2	pos;
	t_vec2	tot;

	pos.y = 0;
	tot.y = offset(mlx->pxl_img,
			ft_tablen((const char **)mlx->map), mlx->img.height);
	while (mlx->map[pos.y] != NULL)
	{
		pos.x = 0;
		tot.x = offset(mlx->pxl_img, ft_strlen(mlx->map[0]), mlx->img.width);
		while (mlx->map[pos.y][pos.x] != '\0')
		{
			if (print == PRINT_FLOOR)
				add_img(mlx, get_anim(&mlx->ref.tile, ANIM_TILE, mlx->time),
					tot.x * 4, tot.y);
			else if (print == PRINT_1CE && (mlx->map[pos.y][pos.x] == '1'
				|| check_for_obj(mlx->gp.coll, pos) == 1
				|| check_for_obj(mlx->gp.exits, pos) == 1))
				add_img(mlx, get_1ce_xpm(mlx, pos), tot.x * 4, tot.y);
			else if (print == PRINT_PM && (mlx->map[pos.y][pos.x] == 'P'
				|| mlx->map[pos.y][pos.x] == 'M'))
				add_img(mlx, get_pm_xpm(mlx, pos), tot.x * 4, tot.y);
			tot.x += mlx->pxl_img;
			pos.x++;
		}
		tot.y += mlx->pxl_img;
		pos.y++;
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
