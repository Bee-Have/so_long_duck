/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:07:32 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/24 15:09:45 by amarini-         ###   ########.fr       */
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
	pos[0] = 0;
	pos[1] = 0;
	while (mlx->map->map[row])
	{
		col = 0;
		while (mlx->map->map[row][col] != '\0')
		{
			if (mlx->map->map[row][col] == 'E')
			{
				pos[0] = row;
				pos[1] = col;
				if (mlx->mobs == NULL)
					printf("ye[, this is normal\n");
				mlx->mobs = init_mobs(mlx->mobs, mlx->map->map, pos, mlx->mobs_count);
				++mlx->mobs_count;
			}
			++col;
		}
		++row;
	}
}
