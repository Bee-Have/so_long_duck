/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:28:25 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/27 16:06:42 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	free_manager(t_mlx_vars *mlx)
{
	free_img(mlx, &mlx->img);
	ft_freetab(mlx->map->map);
	free(mlx->map);
	free_sprites(mlx);
	free_mobs(mlx);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	free(mlx);
	exit(1);
}

void	free_mobs(t_mlx_vars *mlx)
{
	t_mob	*it;
	int		i;

	i = 0;
	while (i < mlx->mobs_count)
	{
		it = mlx->mobs;
		mlx->mobs = mlx->mobs->next;
		free_anim(mlx, &it->anim, 8);
		free(it);
		i++;
	}
	return ;
}

void	free_sprites(t_mlx_vars *mlx)
{
	free_img(mlx, &mlx->ref->wall);
	free_img(mlx, &mlx->ref->wall_n);
	free_img(mlx, &mlx->ref->wall_s);
	free_img(mlx, &mlx->ref->wall_e);
	free_img(mlx, &mlx->ref->wall_w);
	free_img(mlx, &mlx->ref->wall_corner_ne);
	free_img(mlx, &mlx->ref->wall_corner_nw);
	free_img(mlx, &mlx->ref->wall_corner_se);
	free_img(mlx, &mlx->ref->wall_corner_sw);
	free_anim(mlx, &mlx->ref->tile, 4);
	free_anim(mlx, &mlx->ref->obj, 4);
	free_anim(mlx, &mlx->ref->exit, 2);
	free_anim(mlx, &mlx->ref->pj_idle, 5);
	free(mlx->ref);
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

void	free_img(t_mlx_vars *mlx, t_img **img)
{
	mlx_destroy_image(mlx->mlx, (*img)->img);
	free(*img);
	return ;
}
