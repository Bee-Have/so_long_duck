/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:28:25 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/27 17:16:13 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_manager(t_mlx_vars *mlx, int status)
{
	free_img(mlx, &mlx->img);
	ft_freetab(mlx->map);
	//something here to free exits and collectibles
	free_sprites(mlx);
	free_mobs(mlx);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	free(mlx->mlx);
	free(mlx);
	if (status == 0)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

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

void	free_sprites(t_mlx_vars *mlx)
{
	free_img(mlx, &mlx->ref.wall);
	free_img(mlx, &mlx->ref.wall_n);
	free_img(mlx, &mlx->ref.wall_s);
	free_img(mlx, &mlx->ref.wall_e);
	free_img(mlx, &mlx->ref.wall_w);
	free_img(mlx, &mlx->ref.wall_corner_ne);
	free_img(mlx, &mlx->ref.wall_corner_nw);
	free_img(mlx, &mlx->ref.wall_corner_se);
	free_img(mlx, &mlx->ref.wall_corner_sw);
	if (mlx->gp.mobs_count == NOT_BONUS)
	{
		free_anim(mlx, &mlx->ref.tile, 1);
		//this will change since there are multiple collectibles
		// free_anim(mlx, &mlx->ref->obj, 1);
		//this will change since there can be multiple exits
		// free_anim(mlx, &mlx->ref->exit, 1);
		free_anim(mlx, &mlx->gp.pj.pj_idle, 1);
		// free(mlx->ref);
	}
	else
	{
		free_anim(mlx, &mlx->ref.tile, 4);
		//this will change since there are multiple collectibles
		// free_anim(mlx, &mlx->ref->obj, 4);
		//this will change since there can be multiple exits
		// free_anim(mlx, &mlx->ref->exit, 2);
		free_anim(mlx, &mlx->gp.pj.pj_idle, 5);
		// free(mlx->ref);
	}
}

void	free_anim(t_mlx_vars *mlx, t_anim **stack, int len)
{
	t_anim	*it;
	int		i;

	i = 0;
	while (i < len && (*stack)->next)
	{
		it = *stack;
		*stack = (*stack)->next;
		it->next = NULL;
		free_img(mlx, &it->img);
		free(it);
		i++;
	}
}

void	free_img(t_mlx_vars *mlx, t_img *img)
{
	if ((*img).img)
		mlx_destroy_image(mlx->mlx, (*img).img);
	// free(img);
	return ;
}
