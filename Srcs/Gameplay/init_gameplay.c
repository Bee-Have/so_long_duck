/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:12 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/23 12:16:15 by amarini-         ###   ########.fr       */
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
	if (mlx->gp.c_count > 0)
		check = 1;
	while (mlx->map[row])
	{
		col = 0;
		while (mlx->map[row][col] != '\0')
		{
			if (mlx->map[row][col] == 'P')
			{
				mlx->gp.pj.pj_pos[0] = row;
				mlx->gp.pj.pj_pos[1] = col;
			}
			else if (mlx->map[row][col] == 'C' && check == 0)
				++mlx->gp.c_count;
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
	mlx->gp.mobs_count++;
	if (mlx->gp.mobs == NULL)
		mlx->gp.mobs = init_mobs(mlx, map, pos, ++mlx->gp.mobs_count);
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
				//need to completely change how this works
				// mlx->gp.exit_pos[mlx->gp.exits][0] = row;
				// mlx->gp.exit_pos[mlx->gp.exits][1] = col;
				++mlx->gp.exits;
			}
			++col;
		}
		++row;
	}
	return ;
}
