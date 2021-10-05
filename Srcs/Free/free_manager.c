/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:28:25 by amarini-          #+#    #+#             */
/*   Updated: 2021/10/05 18:08:13 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_manager(t_mlx_vars *mlx, int status)
{
	free_img(mlx, &mlx->img);
	ft_freetab(mlx->map);
	if (mlx->gp.anim_mob)
		free_mobs(mlx);
	free_sprites(mlx);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	#ifdef __unix__
	mlx_destroy_display(mlx->mlx);
	#endif
	free(mlx->mlx);
	free(mlx);
	if (status == 0)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
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
	free_anim_manager(mlx);
}

void	free_anim(t_mlx_vars *mlx, t_anim **stack, int len)
{
	t_anim	*it;
	t_anim	*tmp;
	int		i;

	i = 0;
	it = *stack;
	while (i < len)
	{
		free_img(mlx, &it->img);
		tmp = it->next;
		free(it);
		it = tmp;
		i++;
	}
}

void	free_img(t_mlx_vars *mlx, t_img *img)
{
	if (img->img)
		mlx_destroy_image(mlx->mlx, img->img);
	return ;
}
