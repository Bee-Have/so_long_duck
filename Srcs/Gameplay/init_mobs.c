/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:20:23 by amarini-          #+#    #+#             */
/*   Updated: 2021/11/02 14:05:33 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mob	*init_mobs(t_mlx_vars *mlx, char **map, t_vec2 pos, int mobs_count)
{
	t_mob	*it;
	int		i;

	i = 0;
	if (!mlx->gp.mobs)
	{
		mlx->gp.mobs = new_mob(map, pos);
		mlx->gp.mobs->next = mlx->gp.mobs;
		return (mlx->gp.mobs);
	}
	it = mlx->gp.mobs;
	while (i < mobs_count - 1)
	{
		gettimeofday(&it->wait, NULL);
		it = it->next;
		i++;
	}
	it->next = NULL;
	it->next = new_mob(map, pos);
	it->next->next = mlx->gp.mobs;
	return (mlx->gp.mobs);
}

t_mob	*new_mob(char **map, t_vec2 pos)
{
	t_mob	*mob;

	mob = NULL;
	mob = (t_mob *)malloc(sizeof(t_mob));
	if (!mob)
		return (NULL);
	mob->pos.y = pos.y;
	mob->pos.x = pos.x;
	mob->wait.tv_sec = 0;
	mob->wait.tv_usec = 0;
	find_direction(map, pos, &mob->dir);
	mob->next = NULL;
	return (mob);
}

//here, add check of maxes to set direction to 0
void	find_direction(char **map, t_vec2 pos, t_vec2 *dir)
{
	t_vec2	result;
	int		dir_x;
	int		dir_y;

	set_vec2(&result, 0);
	dir_x = 0;
	dir_y = 0;
	find_max_x(map, pos, &dir_x, &result.x);
	find_max_y(map, pos, &dir_y, &result.y);
	if (result.x > result.y)
	{
		(*dir).y = 0;
		(*dir).x = dir_x;
	}
	else
	{
		(*dir).y = dir_y;
		(*dir).x = 0;
	}
}
