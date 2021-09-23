/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:12 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/23 18:40:47 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_mlx_vars *mlx)
{
	int		row;
	int		col;
	int		check;

	row = 0;
	check = 0;
	if (mlx->gp.coll.count > 0)
		check = 1;
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
			else if (mlx->map[row][col] == 'C' && check == 0)
			{
				++mlx->gp.coll.count;
				add_objs(mlx, &mlx->gp.coll, row, col);
			}
			++col;
		}
		++row;
	}
}

void	add_objs(t_mlx_vars *mlx, t_objs_parent *objs, int y, int x)
{
	t_objs	*res;
	int		i;

	i = 0;
	res = (t_objs *)malloc((*objs).count * sizeof(t_objs));
	if (!res)
		return ;
	while (i < (*objs).count)
	{
			res[i].anim = (*objs).obj[i].anim;
			res[i].pos = (*objs).obj[i].pos;
		++i;
	}
	res[i].pos.y = y;
	res[i].pos.x = x;
		res[i].anim = init_anim(mlx, (*objs).sprites, (*objs).path);
		res[i].anim = init_anim(mlx, (*objs).sprites, (*objs).path);
	free((*objs).obj);
	mlx->gp.coll.obj = res;
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
				add_objs(mlx, &mlx->gp.exits, row, col);
			}
			++col;
		}
		++row;
	}
	return ;
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
	mlx->gp.mobs_count++;
	if (mlx->gp.mobs == NULL)
		mlx->gp.mobs = init_mobs(mlx, map, pos, ++mlx->gp.mobs_count);
}
