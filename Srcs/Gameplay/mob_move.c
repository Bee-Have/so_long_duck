/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:36:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/11/02 15:29:49 by amarini-         ###   ########.fr       */
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
		if (it->dir.y != 0 || it->dir.x != 0)
			move_mob(mlx, it, mlx->map);
		it = it->next;
		++i;
	}
	return ;
}

void	move_mob(t_mlx_vars *mlx, t_mob *mob, char **map)
{
	t_vec2	pos_map;

	set_vec2(&pos_map, 0);
	if (check_mob_pos(mlx, mob) == 1
		|| map[mob->pos.y + mob->dir.y][mob->pos.x + mob->dir.x] == 'M'
		|| map[mob->pos.y + mob->dir.y][mob->pos.x + mob->dir.x] == '1'
		|| map[mob->pos.y + mob->dir.y][mob->pos.x + mob->dir.x] == 'E')
		change_mob_dir(mob, map);
	while (map[pos_map.y])
	{
		pos_map.x = 0;
		while (map[pos_map.y][pos_map.x] != '\0')
		{
			if (mob->pos.y == pos_map.y && mob->pos.x == pos_map.x
				&& map[pos_map.y][pos_map.x] != '1')
			{
				if (map[pos_map.y][pos_map.x] == 'P')
					free_manager(mlx, 1);
				map[pos_map.y][pos_map.x] = 'M';
				erase_old_pos(mob, map);
			}
			++pos_map.x;
		}
		++pos_map.y;
	}
}

void	change_mob_dir(t_mob *mob, char **map)
{
	erase_old_pos(mob, map);
	mob->dir.y *= -1;
	mob->dir.x *= -1;
	return ;
}

void	erase_old_pos(t_mob *mob, char **map)
{
	t_vec2		old_pos;

	old_pos.y = mob->pos.y - mob->dir.y;
	old_pos.x = mob->pos.x - mob->dir.x;
	if (map[old_pos.y][old_pos.x] != '1'
		&& map[old_pos.y][old_pos.x] != 'P')
		map[old_pos.y][old_pos.x] = '0';
}

int	check_mob_pos(t_mlx_vars *mlx, t_mob *mob)
{
	t_mob	*it;
	int		i;

	it = mob;
	i = 0;
	if (mob->pos.y + mob->dir.y >= ft_tablen((const char **)mlx->map)
		|| mob->pos.x + mob->dir.x >= ft_strlen(mlx->map[0])
		|| mob->pos.y + mob->dir.y <= 0
		|| mob->pos.x + mob->dir.x <= 0)
		return (1);
	while (i < mlx->gp.mobs_count)
	{
		if (it->pos.y == mob->pos.y + mob->dir.y
			&& it->pos.x == mob->pos.x + mob->dir.x)
			return (1);
		it = it->next;
		++i;
	}
	return (0);
}
