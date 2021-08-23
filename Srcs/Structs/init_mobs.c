/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:20:23 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/23 20:22:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_mob	*init_mobs(t_mob *mobs, char **map, int *pos)
{
	t_mob	*it;
	int		i;

	if (!mobs)
	{
		new_mob(map, pos);
		return (mobs);
	}
	it = mobs;
	while (it->next)
		it = it->next;
	it->next = new_mob(map, pos);
	return (mobs);
}

t_mob	*new_mob(char **map, int *pos)
{
	t_mob	*mob;

	mob = NULL;
	mob = (t_mob *)malloc(sizeof(t_mob));
	if (!mob)
		return (NULL);
	mob->pos = pos;
	mob->wait = find_max(map, pos);
	mob->anim = init_anim(8, "./Sprites/Characters/Slime/");
	mob->next = NULL;
	return (mob);
}

int	find_max(char **map, int *pos)
{
	int		max;
	int		row;
	int		col;
	int		i;

	max = 0;
	row = pos[0];
	col = pos[1];
	i = 1;
	while (map[row])
	{
		max = check_max(map[row][col], row, pos[0], &i, max);
		if (i == 0)
		{
			i = 1;
			break ;
		}
		row += i;
	}
	row = pos[0];
	while (map[row][col] != '\0')
	{
		max = check_max(map[row][col], col, pos[1], &i, max);
		if (i == 0)
			break ;
		col += i;
	}
	return (max);
}

int	check_max(char c, int cmp, int pos, int *i, int max)
{
	if (c == '1')
	{
		if (cmp > pos && cmp - pos > max)
		{
			max = cmp = pos;
			*i = -1;
		}
		else if (cmp < pos)
		{
			if (pos - cmp > max)
				max = pos;
			*i = 0;
		}
	}
	return (max);
}
