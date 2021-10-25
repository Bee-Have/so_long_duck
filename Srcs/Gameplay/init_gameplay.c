/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:12 by amarini-          #+#    #+#             */
/*   Updated: 2021/10/25 11:46:02 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_mlx_vars *mlx)
{
	int		row;
	int		col;

	row = 0;
	while (mlx->map[row])
	{
		col = 0;
		while (mlx->map[row][col] != '\0')
		{
			if (mlx->map[row][col] == 'P')
			{
				mlx->gp.pj.pj_pos.y = row;
				mlx->gp.pj.pj_pos.x = col;
			}
			++col;
		}
		++row;
	}
}

void	add_objs(t_objs_parent *objs, int y, int x)
{
	t_vec2	*res;
	int		i;

	i = 0;
	res = (t_vec2 *)malloc((*objs).count * sizeof(t_vec2));
	if (!res)
		return ;
	while (i < (*objs).count - 1)
	{
		res[i] = (*objs).pos[i];
		++i;
	}
	res[i].y = y;
	res[i].x = x;
	if ((*objs).pos)
		free((*objs).pos);
	(*objs).pos = res;
}

void	find_exits(t_mlx_vars *mlx, char **map)
{
	int		row;
	int		col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'E')
			{
				++mlx->gp.exits.count;
				add_objs(&mlx->gp.exits, row, col);
			}
			else if (mlx->map[row][col] == 'C')
			{
				++mlx->gp.coll.count;
				add_objs(&mlx->gp.coll, row, col);
			}
			++col;
		}
		++row;
	}
}

void	find_mobs(t_mlx_vars *mlx, char **map)
{
	int		row;
	int		col;
	int		pos[2];

	row = 0;
	pos[0] = 0;
	pos[1] = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'M')
			{
				pos[0] = row;
				pos[1] = col;
				mlx->gp.mobs = init_mobs(mlx, map, pos, ++mlx->gp.mobs_count);
			}
			++col;
		}
		++row;
	}
	if (mlx->gp.mobs_count > -1)
		mlx->gp.mobs_count++;
}
