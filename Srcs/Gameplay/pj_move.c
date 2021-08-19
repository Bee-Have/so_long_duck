/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:33:28 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/19 13:38:25 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	move_pj_map_pos(t_mlx_vars *mlx, int *pos)
{
	int		row;
	int		col;

	row = 0;
	mlx->map->pj_moved = 0;
	if (mlx->map->map[pos[0]][pos[1]] == 'P'
		|| mlx->map->map[pos[0]][pos[1]] == '1')
		return ;
	while (mlx->map->map[row] != NULL)
	{
		col = 0;
		while (mlx->map->map[row][col] != '\0')
		{
			if (pos[0] == row && pos[1] == col
				&& mlx->map->map[row][col] != '1')
				mlx->map->map[row][col] = 'P';
			// else if (mlx->map->map[row][col] == 'E')
				// do something here
			else if (mlx->map->map[row][col] == 'P')
				mlx->map->map[row][col] = '0';
			col++;
		}
		row++;
	}
	mlx->map->moves++;
}
