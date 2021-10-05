/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:59:08 by user42            #+#    #+#             */
/*   Updated: 2021/10/05 18:02:22 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mobs(t_mlx_vars *mlx)
{
	t_mob	*it;
	int		i;

	i = 0;
	if (mlx->gp.mobs_count == NOT_BONUS)
		return ;
	free_anim(mlx, &mlx->gp.anim_mob, SPRITES_MOB);
	while (i < mlx->gp.mobs_count)
	{
		it = mlx->gp.mobs;
		mlx->gp.mobs = mlx->gp.mobs->next;
		free(it);
		i++;
	}
	return ;
}

void	free_anim_manager(t_mlx_vars *mlx)
{
	free(mlx->gp.exits.pos);
	free(mlx->gp.coll.pos);
	if (mlx->gp.mobs_count == NOT_BONUS)
	{
		free_anim(mlx, &mlx->gp.exits.anim, 1);
		free_anim(mlx, &mlx->gp.coll.anim, 1);
		free_anim(mlx, &mlx->ref.tile, 1);
		free_anim(mlx, &mlx->gp.pj.pj_idle, 1);
	}
	else
	{
		free_anim(mlx, &mlx->gp.exits.anim, SPRITES_EXIT);
		free_anim(mlx, &mlx->gp.coll.anim, SPRITES_COLL);
		free_anim(mlx, &mlx->ref.tile, SPRITES_TILE);
		free_anim(mlx, &mlx->gp.pj.pj_idle, SPRITES_PJ);
	}
}
