/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mobs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:32:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/11/02 15:26:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_max_x(char **map, t_vec2 pos, int *dir, int *max)
{
	int	i;
	int	rev;

	i = pos.x;
	rev = 0;
	while (map[pos.y][i] != '\0')
	{
		if (map[pos.y][i] == '1' || map[pos.y][i] == 'E'
			|| (map[pos.y][i] == 'M' && i != pos.x))
		{
			if (rev == 0)
				rev = assign_dir_max(max, dir, i, pos.x);
			else if (rev == 1)
			{
				assign_dir_max(max, dir, i, pos.x);
				return ;
			}
		}
		if (rev == 1)
			--i;
		else
			++i;
	}
}

void	find_max_y(char **map, t_vec2 pos, int *dir, int *max)
{
	int	i;
	int	rev;

	i = pos.y;
	rev = 0;
	while (map[i])
	{
		if (map[i][pos.x] == '1' || map[i][pos.x] == 'E'
			|| (map[i][pos.x] == 'M' && i != pos.y))
		{
			if (rev == 0)
				rev = assign_dir_max(max, dir, i, pos.y);
			else
			{
				assign_dir_max(max, dir, i, pos.y);
				return ;
			}
		}
		if (rev == 1)
			--i;
		else
			++i;
	}
}

int	assign_dir_max(int *max, int *dir, int i, int pos)
{
	if (i > pos && (i - pos) > 1)
	{
		*max = i - pos;
		*dir = 1;
	}
	else if (pos > i && (pos - i) > *max && (pos - i) > 1)
	{
		*max = pos - i;
		*dir = -1;
	}
	return (1);
}
