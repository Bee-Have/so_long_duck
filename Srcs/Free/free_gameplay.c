/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:59:08 by user42            #+#    #+#             */
/*   Updated: 2021/10/04 17:11:14 by user42           ###   ########.fr       */
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
	free_anim(mlx, &mlx->gp.anim_mob, 8);
	while (i < mlx->gp.mobs_count)
	{
		it = mlx->gp.mobs;
		mlx->gp.mobs = mlx->gp.mobs->next;
		free(it);
		i++;
	}
	return ;
}

void	free_objs(t_mlx_vars *mlx)
{
	free(mlx->gp.exits.pos);
	free_anim(mlx, &mlx->gp.exits.anim, mlx->gp.exits.sprites);
	free(mlx->gp.coll.pos);
	free_anim(mlx, &mlx->gp.coll.anim, mlx->gp.coll.sprites);
	return ;
}
