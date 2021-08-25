/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:37:26 by user42            #+#    #+#             */
/*   Updated: 2021/08/25 13:26:25 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

char	*get_mob(int play_time, int x, int y, t_mob *mobs)
{
	while (mobs->pos[0] != y && mobs->pos[1] != x)
	{
		// printf("y-[%d][%d]_x-[%d][%d]\n", y, mobs->pos[0], x, mobs->pos[1]);
		mobs = mobs->next;
	}
	// printf("mob-[%s]\n", mobs->anim->img);
	if (mobs->moves < mobs->wait && mobs->anim->played <= play_time)
	{
		mobs->pos[0] += mobs->dir[0];
		mobs->pos[1] += mobs->dir[1];
	}
	return (get_anim(&mobs->anim, play_time));
}

void	move_mob_manager(t_mlx_vars *mlx)
{
	t_mob	*it;
	int		old_pos[2];
	int		i;

	it = mlx->mobs;
	i = 0;
	// printf("dir-[%d][%d]\n", mlx->mobs->dir[0], mlx->mobs->dir[1]);
	while(i < mlx->mobs_count)
	{
		if (it->dir[0] > 0 || it->dir[1] > 0)
		{
			old_pos[0] = it->pos[0] - it->dir[0];
			old_pos[1] = it->pos[1] - it->dir[1];
		}
		else
		{
			old_pos[0] = it->pos[0] + it->dir[0];
			old_pos[1] = it->pos[1] + it->dir[1];
		}
		mlx->map->map[old_pos[0]][old_pos[1]] = '0';
		mlx->map->map[it->pos[0]][it->pos[1]] = 'M';
		++mlx->mobs->moves;
		it = it->next;
		i++;
	}
}
