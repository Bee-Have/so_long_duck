/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mobs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:32:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/27 16:04:01 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	find_max_x(char **map, int *pos, int (*dir)[2], int *max, int col)
{
	while (map[pos[0]][col] != '\0')
	{
		if (map[pos[0]][col] == '1')
		{
			if (col > pos[1])
			{
				(*max) = col - pos[1];
				(*dir)[1] = 1;
				col = pos[1];
			}
			else
			{
				if (pos[1] - col > (*max))
				{
					(*max) = pos[1] - col;
					(*dir)[1] = -1;
				}
				return ;
			}
		}
		if ((*dir)[1] == 1)
			--col;
		else
			++col;
	}
}

void	find_max_y(char **map, int *pos, int (*dir)[2], int *max, int row)
{
	while (map[row])
	{
		if (map[row][pos[1]] == '1')
		{
			if (row > pos[0])
			{
				(*max) = row - pos[0];
				(*dir)[0] = 1;
				row = pos[0];
			}
			else
			{
				if (pos[0] - row > (*max))
				{
					(*max) = pos[0] - row;
					(*dir)[0] = -1;
				}
				return ;
			}
		}
		if ((*dir)[0] == 1)
			--row;
		else
			++row;
	}
}
