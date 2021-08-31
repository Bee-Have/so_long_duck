/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:07:32 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/31 15:09:03 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	find_player(t_mlx_vars *mlx)
{
	int		row;
	int		col;

	row = 0;
	while (mlx->map->map[row])
	{
		col = 0;
		while (mlx->map->map[row][col] != '\0')
		{
			if (mlx->map->map[row][col] == 'P')
			{
				mlx->map->pj_pos[0] = row;
				mlx->map->pj_pos[1] = col;
				return ;
			}
			col++;
		}
		row++;
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
				++mlx->mobs_count;
				pos[0] = row;
				pos[1] = col;
				mlx->mobs = init_mobs(mlx, map, pos, mlx->mobs_count);
			}
			++col;
		}
		++row;
	}
	mlx->mobs_count++;
	if (mlx->mobs == NULL)
		mlx->mobs = init_mobs(mlx, map, pos, ++mlx->mobs_count);
}
