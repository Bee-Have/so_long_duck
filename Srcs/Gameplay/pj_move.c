/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pj_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:33:28 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/10 18:52:49 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	move_pj_map_pos(t_map_info *map_info, int *pos)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (map_info->map[row] != NULL)
	{
		while (map_info->map[row][col] != '\0')
		{
			if (pos[0] == row && pos[1] == col)
			{
				if (map_info->map[row][col] == '1')
					return ;
				map_info->map[row][col] = 'P';
			}
			else if (map_info->map[row][col] == 'P')
				map_info->map[row][col] = 0;
			col++;
		}
		col = 0;
		row++;
	}
}