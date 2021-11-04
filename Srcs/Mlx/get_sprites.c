/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:29:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/11/04 17:29:07 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	get_wall(char **map, t_refs textures, int row, int col)
{
	if (col == 0 && row == 0)
		return (textures.wall_corner_nw);
	else if (col == ft_strlen(map[row]) - 1 && row == 0)
		return (textures.wall_corner_ne);
	else if (col > 0 && col < ft_strlen(map[row]) - 1 && row == 0)
		return (textures.wall_n);
	else if (col == 0 && row == ft_tablen((const char **)map) - 1)
		return (textures.wall_corner_sw);
	else if (col == ft_strlen(map[row]) - 1
		&& row == ft_tablen((const char **)map) - 1)
		return (textures.wall_corner_se);
	else if (col > 0 && col < ft_strlen(map[row]) - 1
		&& row == ft_tablen((const char **)map) - 1 )
		return (textures.wall_s);
	else if (col == 0 && row > 0 && row < ft_tablen((const char **)map) - 1)
		return (textures.wall_w);
	else if (col == ft_strlen(map[row]) - 1 && row > 0
		&& row < ft_tablen((const char **)map) - 1)
		return (textures.wall_e);
	return (textures.wall);
}

t_img	get_anim(t_anim **anim, int max_time, struct timeval current)
{
	long int		playing_time;

	playing_time = ((current.tv_sec - (*anim)->played.tv_sec) * 1000)
		+ ((current.tv_usec - (*anim)->played.tv_usec) / 1000);
	if (playing_time >= max_time)
	{
		(*anim) = (*anim)->next;
		(*anim)->played = current;
	}
	return ((*anim)->img);
}

t_img	get_mob(t_mlx_vars *mlx, int y, int x)
{
	t_mob		*mobs;
	t_img		result;
	long int	timer;

	mobs = mlx->gp.mobs;
	while (mobs->pos.y != y || mobs->pos.x != x)
		mobs = mobs->next;
	timer = ((mlx->time.tv_sec - mobs->wait.tv_sec) * 1000)
		+ ((mlx->time.tv_usec - mobs->wait.tv_usec) / 1000);
	if (timer >= MOVE_MOB)
	{
		gettimeofday(&mobs->wait, NULL);
		move_mob(mlx, mobs, mlx->map);
	}
	result = get_anim(&mlx->gp.anim_mob, ANIM_MOB, mlx->time);
	if (mobs->dir.x == 1)
		result.rev_print = 1;
	else
		result.rev_print = 0;
	return (result);
}
