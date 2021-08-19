/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:07:32 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/19 12:11:33 by amarini-         ###   ########.fr       */
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
