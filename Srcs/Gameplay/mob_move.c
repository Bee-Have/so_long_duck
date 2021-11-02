/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:36:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/11/02 18:20:05 by amarini-         ###   ########.fr       */
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
		if ((it->dir.y != 0 || it->dir.x != 0)
			&& (mlx->map[it->pos.y + it->dir.y][it->pos.x + it->dir.x] == 'M'
			|| mlx->map[it->pos.y + it->dir.y][it->pos.x + it->dir.x] == '1'
			|| mlx->map[it->pos.y + it->dir.y][it->pos.x + it->dir.x] == 'E')
			&& check_mob_stuck(mlx->map, it) == 0)
		{
			it->dir.y *= -1;
			it->dir.x *= -1;
		}
		it = it->next;
		++i;
	}
	return ;
}

int	check_mob_stuck(char **map, t_mob *mob)
{
	t_vec2	invert;

	invert.y = mob->dir.y * -1;
	invert.x = mob->dir.x * -1;
	if ((map[mob->pos.y + mob->dir.y][mob->pos.x + mob->dir.x] == 'M'
		|| map[mob->pos.y + mob->dir.y][mob->pos.x + mob->dir.x] == 'E'
		|| map[mob->pos.y + mob->dir.y][mob->pos.x + mob->dir.x] == '1') &&
		(map[mob->pos.y + invert.y][mob->pos.x + invert.x] == 'M'
		|| map[mob->pos.y + invert.y][mob->pos.x + invert.x] == 'E'
		|| map[mob->pos.y + invert.y][mob->pos.x + invert.x] == '1'))
		return (1);
	return (0);
}

void	move_mob(t_mlx_vars *mlx, t_mob *mob, char **map)
{
	if (mob->pos.y + mob->dir.y >= ft_tablen((const char **)mlx->map)
		|| mob->pos.x + mob->dir.x >= ft_strlen(mlx->map[0])
		|| mob->pos.y + mob->dir.y <= 0 || mob->pos.x + mob->dir.x <= 0
		|| map[mob->pos.y + mob->dir.y][mob->pos.x + mob->dir.x] == 'M'
		|| map[mob->pos.y + mob->dir.y][mob->pos.x + mob->dir.x] == '1'
		|| map[mob->pos.y + mob->dir.y][mob->pos.x + mob->dir.x] == 'E')
		return ;
	map[mob->pos.y][mob->pos.x] = '0';
	mob->pos.y += mob->dir.y;
	mob->pos.x += mob->dir.x;
	if (map[mob->pos.y][mob->pos.x] == 'P')
		free_manager(mlx, 1);
	map[mob->pos.y][mob->pos.x] = 'M';
}
