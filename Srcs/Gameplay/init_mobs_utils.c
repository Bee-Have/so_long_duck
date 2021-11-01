/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mobs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:32:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/11/01 11:56:15 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_max_x(char **map, t_vec2 pos, t_vec2 *dir, int *max)
{
	int	i;
	int	tmp_dir;
	int	rev;

	i = pos.x;
	tmp_dir = 0;
	rev = 0;
	while (map[pos.y][i] != '\0')
	{
		if (map[pos.y][i] == '1' || map[pos.y][i] == 'E'
			|| (map[pos.y][i] == 'M' && i != pos.x))
		{
			if (rev == 0)
			{
				tmp_dir = i - pos.x;
				rev = 1;
			}
			else
			{
				if ((pos.x - i) > tmp_dir)
					tmp_dir = pos.x - i;
				break ;
			}
		}
		if (rev == 1)
			--i;
		else
			++i;
	}
	if (tmp_dir > 0)
	{
		
	}
	(*max) = tmp_dir;
}
// void	find_max_x(char **map, int *pos, t_vec2 *dir, int *max)
// {
// 	int	i;

// 	i = pos[1];
// 	while (map[pos[0]][i] != '\0')
// 	{
// 		if (map[pos[0]][i] == '1'  || map[pos[0]][i] == 'E'
// 		|| map[pos[0]][i] == 'P' || (map[pos[0]][i] == 'M' && pos[1] != i))
// 		{
// 			if (i > pos[1])
// 			{
// 				(*max) = i - pos[1];
// 				(*dir).x = 1;
// 				i = pos[1];
// 			}
// 			if (pos[1] - i > (*max))
// 			{
// 				(*max) = pos[1] - i;
// 				(*dir).x = -1;
// 			}
// 			if (i == pos[1])
// 			{
// 				(*max) = pos[1];
// 				(*dir).x = 0;
// 			}
// 			return ;
// 		}
// 		if ((*dir).x == 1)
// 			--i;
// 		else
// 			++i;
// 	}
// }

void	find_max_y(char **map, int *pos, t_vec2 *dir, int *max)
{
	int	i;

	i = pos[0];
	while (map[i])
	{
		if ((map[i][pos[1]] == '1' || map[i][pos[1]] == 'E'
		|| map[i][pos[1]] == 'P' || (map[i][pos[1]] == 'M' && pos[0] != i)))
		{
			if (i > pos[0] && i > (*max))
			{
				(*max) = i - pos[0];
				(*dir).y = 1;
				i = pos[0];
			}
			else if (pos[0] - i > (*max))
			{
				(*max) = pos[0] - i;
				(*dir).y = -1;
			}
			else if (pos[0] == i)
			{
				(*max) = pos[0];
				(*dir).y = 0;
			}
			break ;
		}
		if ((*dir).y == 1)
			--i;
		else
			++i;
	}
}
