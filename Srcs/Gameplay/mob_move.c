/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:37:26 by user42            #+#    #+#             */
/*   Updated: 2021/08/27 15:52:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_img	*get_mob(int play_time, int x, int y, t_mob *mobs)
{
	while (mobs->pos[0] != y && mobs->pos[1] != x)
		mobs = mobs->next;
	return (get_anim(&mobs->anim, 3));
}

void	move_mob_manager(t_mlx_vars *mlx)
{
	//for now this will stay empty
	//just try to make it work without moving them first
}
