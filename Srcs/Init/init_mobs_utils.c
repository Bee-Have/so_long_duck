/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mobs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:32:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/10/27 17:41:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_max_x(char **map, int *pos, t_vec2 *dir, int *max)
{
	int	i;

	i = pos[1];
	while (map[pos[0]][i] != '\0')
	{
		if (map[pos[0]][i] == '1' && i > pos[1])
		{
			(*max) = i - pos[1];
			(*dir).x = 1;
			i = pos[1];
		}
		else if (map[pos[0]][i] == '1')
		{
			if (pos[1] - i > (*max))
			{
				(*max) = pos[1] - i;
				(*dir).x = -1;
			}
			return ;
		}
		if ((*dir).x == 1)
			--i;
		else
			++i;
	}
}

void	find_max_y(char **map, int *pos, t_vec2 *dir, int *max)
{
	int	i;

	i = pos[0];
	while (map[i])
	{
		if (map[i][pos[1]] == '1' && i > pos[0])
		{
			(*max) = i - pos[0];
			(*dir).y = 1;
			i = pos[0];
		}
		else if (map[i][pos[1]] == '1')
		{
			if (pos[0] - i > (*max))
			{
				(*max) = pos[0] - i;
				(*dir).y = -1;
			}
			return ;
		}
		if ((*dir).y == 1)
			--i;
		else
			++i;
	}
}
