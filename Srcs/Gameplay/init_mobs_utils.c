/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mobs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:32:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/11/01 14:09:31 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_max_x(char **map, t_vec2 pos, int *dir, int *max)
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
				if ((i - pos.x) > 1)
				{
					tmp_dir = i - pos.x;
					(*dir) = 1;
				}
				i = pos.x + 1;
				rev = 1;
			}
			else if (rev == 1)
			{
				if ((pos.x - i) > tmp_dir && (pos.x - i) > 1)
				{
					tmp_dir = pos.x - i;
					(*dir) = -1;
				}
				break ;
			}
		}
		if (rev == 1)
			--i;
		else
			++i;
	}
	if (tmp_dir == 0)
		(*dir) = 0;
	(*max) = tmp_dir;
}

void	find_max_y(char **map, t_vec2 pos, int *dir, int *max)
{
	int	i;
	int	tmp_dir;
	int	rev;

	i = pos.y;
	tmp_dir = 0;
	rev = 0;
	while (map[i])
	{
		if (map[i][pos.x] == '1' || map[i][pos.x] == 'E'
			|| (map[i][pos.x] == 'M' && i != pos.y))
		{
			if (rev == 0)
			{
				if ((i - pos.y) > 1)
				{
					tmp_dir = i - pos.y;
					(*dir) = 1;
				}
				i = pos.y + 1;
				rev = 1;
			}
			else
			{
				if ((pos.y - i) > tmp_dir && (pos.y - i) > 1)
				{
					tmp_dir = pos.y - i;
					(*dir) = -1;
				}
				break ;
			}
		}
		if (rev == 1)
			--i;
		else
			++i;
	}
	if (tmp_dir == 0)
		(*dir) = 0;
	(*max) = tmp_dir;
}
