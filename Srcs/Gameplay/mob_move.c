/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:36:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/10/25 11:47:09 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_mob_manager(t_mlx_vars *mlx)
{
	t_mob	*it;
	int		i;

	if (!mlx->gp.mobs)
		return ;
	it = mlx->gp.mobs;
	i = 0;
	while (i < mlx->gp.mobs_count)
	{
		move_mob(mlx, it, mlx->map);
		it = it->next;
		++i;
	}
	return ;
}

void	move_mob(t_mlx_vars *mlx, t_mob *mob, char **map)
{
	int		row;
	int		col;

	row = 0;
	if (map[mob->pos.y][mob->pos.x] == '1'
		|| map[mob->pos.y][mob->pos.x] == 'E')
		change_mob_dir(mob);
	else
		erase_old_pos(mob, map);
	while (map[row])
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (mob->pos.y == row && mob->pos.x == col
				&& map[row][col] != '1')
			{
				if (map[row][col] == 'P')
					free_manager(mlx, 1);
				map[row][col] = 'M';
			}
			++col;
		}
		++row;
	}
}

void	change_mob_dir(t_mob *mob)
{
	if (mob->dir.y > 0)
		mob->dir.y = -1;
	else if (mob->dir.y < 0)
		mob->dir.y = 1;
	if (mob->dir.x > 0)
		mob->dir.x = -1;
	else if (mob->dir.x < 0)
		mob->dir.x = 1;
	mob->pos.y += mob->dir.y;
	mob->pos.x += mob->dir.x;
}

void	erase_old_pos(t_mob *mob, char **map)
{
	t_vec2		old_pos;

	old_pos.y = mob->pos.y;
	old_pos.x = mob->pos.x;
	old_pos.y = mob->pos.y - mob->dir.y;
	old_pos.x = mob->pos.x - mob->dir.x;
	if (map[old_pos.y][old_pos.x] != '1'
		&& map[old_pos.y][old_pos.x] != 'P')
		map[old_pos.y][old_pos.x] = '0';
}
