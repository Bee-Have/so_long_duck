/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:20:23 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/23 19:16:09 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_mob	*init_mobs(t_mob *mobs, int *pos)
{
	t_mob	*it;
	int		i;

	if (!mobs)
	{
		//init mobs;
	}
	it = mobs;
	while (it->next)
		it = it->next;
	it->next = //init new mob with *pos;
}

t_mob	*new_mob(int *pos)
{
	t_mob	*mob;

	mob = NULL;
	mob = (t_mob *)malloc(sizeof(t_mob));
	if (!mob)
		return (NULL);
	mob->anim = init_anim(8, "./Sprites/Characters/Slime/");
	mob->wait = 
}

int	
