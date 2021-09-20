/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2021/09/20 12:34:04 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	find_player(t_mlx_vars *mlx)
{
	int		row;
	int		col;
	int		check;

	row = 0;
	check = 0;
	while (mlx->map->map[row])
	{
		col = 0;
		while (mlx->map->map[row][col] != '\0')
		{
			if (mlx->map->map[row][col] == 'P')
			{
				++check;
				mlx->map->pj_pos[0] = row;
				mlx->map->pj_pos[1] = col;
			}
			else if (mlx->map->map[row][col] == 'C')
				++mlx->c_count;
			++col;
		}
		++row;
	}
	if (check > 1)
		return (error_message("MAP contains more than ONE PLAYER"));
	return (0);
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
				mlx->mobs = init_mobs(mlx, map, pos, ++mlx->mobs_count);
			}
			++col;
		}
		++row;
	}
	mlx->mobs_count++;
	if (mlx->mobs == NULL)
		mlx->mobs = init_mobs(mlx, map, pos, ++mlx->mobs_count);
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
				mlx->map->exit_pos[mlx->map->exits][0] = row;
				mlx->map->exit_pos[mlx->map->exits][1] = col;
				++mlx->map->exits;
			}
			++col;
		}
		++row;
	}
	return ;
}
