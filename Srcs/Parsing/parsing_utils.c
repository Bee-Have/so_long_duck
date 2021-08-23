/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:07:32 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/23 20:34:17 by user42           ###   ########.fr       */
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

void	find_mobs(t_mlx_vars *mlx)
{
	int		row;
	int		col;
	int		pos[2];

	row = 0;
	while (mlx->map->map[row])
	{
		col = 0;
		while (mlx->map->map[row][col] != '\0')
		{
			if (mlx->map->map[row][col] == 'E')
			{
				pos[0] = row;
				pos[1] = col;
				mlx->mobs = init_mobs(mlx->mobs, mlx->map->map, pos);
			}
			++col;
		}
		++row;
	}
}
