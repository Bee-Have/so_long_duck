/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:33:56 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/23 12:52:01 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_pj_map_pos(t_mlx_vars *mlx, int *pos)
{
	int		row;
	int		col;

	row = 0;
	if (mlx->map[pos[0]][pos[1]] == 'P' || mlx->map[pos[0]][pos[1]] == '1')
		return ;
	while (mlx->map[row] != NULL)
	{
		col = 0;
		while (mlx->map[row][col] != '\0')
		{
			if (pos[0] == row && pos[1] == col && mlx->map[row][col] != '1')
				mlx->map[row][col] = 'P';
			else if ((mlx->map[pos[0]][pos[1]] == 'E' && mlx->gp.c_count == 0)
				|| mlx->map[pos[0]][pos[1]] == 'M')
				free_manager(mlx, 1);
			else if (mlx->map[row][col] == 'P')
				mlx->map[row][col] = '0';
			col++;
		}
		row++;
	}
	mlx->gp.pj.moves++;
	if (mlx->gp.mobs_count == -1)
		print_manager_console(mlx->gp.pj.moves);
}
