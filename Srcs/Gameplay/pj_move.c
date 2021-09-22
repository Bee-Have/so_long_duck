/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:33:56 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/22 14:36:13 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_pj_map_pos(t_mlx_vars *mlx, t_map *map, int *pos)
{
	int		row;
	int		col;

	row = 0;
	if (map->map[pos[0]][pos[1]] == 'P' || map->map[pos[0]][pos[1]] == '1')
		return ;
	while (map->map[row] != NULL)
	{
		col = 0;
		while (map->map[row][col] != '\0')
		{
			if (pos[0] == row && pos[1] == col && map->map[row][col] != '1')
				map->map[row][col] = 'P';
			else if ((map->map[pos[0]][pos[1]] == 'E' && mlx->c == 0)
				|| map->map[pos[0]][pos[1]] == 'M')
				free_manager(mlx);
			else if (map->map[row][col] == 'P')
				map->map[row][col] = '0';
			col++;
		}
		row++;
	}
	mlx->map->moves++;
	if (mlx->mobs_count == -1)
		print_manager_console(mlx->map->moves);
}
