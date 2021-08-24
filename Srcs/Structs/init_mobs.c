/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:20:23 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/24 15:29:52 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_mob	*init_mobs(t_mob *mobs, char **map, int *pos, int mobs_count)
{
	t_mob	*it;
	int		i;

	i = 0;
	printf("pos[0][%d]\n", pos[0]);
	printf("pos[1][%d]\n", pos[1]);
	if (!mobs)
	{
		new_mob(map, pos);
		printf("first_mob-[%s]\n", mobs->anim->img);
		return (mobs);
	}
	it = mobs;
	while (i < mobs_count)
		it = it->next;
	it->next = NULL;
	it->next = new_mob(map, pos);
	it->next->next = mobs;
	return (mobs);
}

t_mob	*new_mob(char **map, int *pos)
{
	t_mob	*mob;

	mob = NULL;
	mob = (t_mob *)malloc(sizeof(t_mob));
	if (!mob)
		return (NULL);
	mob->pos[0] = pos[0];
	mob->pos[1] = pos[1];
	mob->wait = 0;
	find_direction(map, pos, &mob->dir, &mob->wait);
	mob->moves = 0;
	mob->anim = init_anim(8, "./Sprites/Characters/Slime/");
	mob->next = NULL;
	return (mob);
}

void	find_direction(char **map, int *pos, int (*dir)[2], int *max)
{
	int		max_x;
	int		max_y;
	int		dir_x[2];
	int		dir_y[2];

	max_x = 0;
	max_y = 0;
	dir_x[0] = 0;
	dir_x[1] = 0;
	dir_y[0] = 0;
	dir_y[1] = 0;
	find_max_x(map, pos, &dir_x, &max_x, pos[1]);
	find_max_y(map, pos, &dir_y, &max_y, pos[1]);
	if (max_x > max_y)
	{
		*max = max_x;
		(*dir)[0] = dir_x[0];
		(*dir)[1] = dir_x[1];
	}
	else
	{
		*max = max_y;
		(*dir)[0] = dir_y[0];
		(*dir)[1] = dir_y[1];
	}
}
