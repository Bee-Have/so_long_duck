/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:37:26 by user42            #+#    #+#             */
/*   Updated: 2021/08/25 15:35:14 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

char	*get_mob(int play_time, int x, int y, t_mob *mobs)
{
	//first -> find the right mob
	while (mobs->pos[0] != y && mobs->pos[1] != x)
		mobs = mobs->next;
	//then ->return it's anim
	return (get_anim(&mobs->anim, 3));
	//this function will return the animation a mob
}

void	move_mob_manager(t_mlx_vars *mlx)
{
	//for now this will stay empty
	//just try to make it work without moving them first
}
