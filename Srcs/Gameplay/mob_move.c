/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:37:26 by user42            #+#    #+#             */
/*   Updated: 2021/08/30 17:35:37 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	move_mob_manager(t_mlx_vars *mlx)
{
	t_mob	*it;
	int		i;

	it = mlx->mobs;
	i = 0;
	while (i < mlx->mobs_count)
	{
		move_mob(it, mlx->map->map);
		it = it->next;
		++i;
	}
	return ;
}

void	move_mob(t_mob *mob, char **map)
{
	int		row;
	int		col;
	int		old_pos[2];

	row = 0;
	if (map[mob->pos[0]][mob->pos[1]] == '1'
		|| map[mob->pos[0]][mob->pos[1]] == 'E')
		change_mob_dir(mob, map);
	else
	{
		get_mob_old_pos(mob, map, &old_pos);
		if (map[old_pos[0]][old_pos[1]] != '1'
			&& map[old_pos[0]][old_pos[1]] != 'P')
			map[old_pos[0]][old_pos[1]] = '0';
	}
	while (map[row])
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (mob->pos[0] == row && mob->pos[1] == col
				&& map[row][col] != '1')
				map[row][col] = 'M';
			++col;
		}
		++row;
	}
}

void	change_mob_dir(t_mob *mob, char **map)
{
	if (mob->dir[0] > 0)
		mob->dir[0] = -1;
	else if (mob->dir[0] < 0)
		mob->dir[0] = 1;
	if (mob->dir[1] > 0)
		mob->dir[1] = -1;
	else if (mob->dir[1] < 0)
		mob->dir[1] = 1;
	mob->pos[0] += mob->dir[0];
	mob->pos[1] += mob->dir[1];
}

void	get_mob_old_pos(t_mob *mob, char **map, int (*old_pos)[2])
{
	(*old_pos)[0] = mob->pos[0];
	(*old_pos)[1] = mob->pos[1];
	(*old_pos)[0] = mob->pos[0] - mob->dir[0];
	(*old_pos)[1] = mob->pos[1] - mob->dir[1];
}
