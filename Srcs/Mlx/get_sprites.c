/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:29:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/27 16:31:15 by amarini-         ###   ########.fr       */
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

t_img	get_right_xpm(t_mlx_vars *mlx, int row, int col)
{
	if (mlx->map[row][col] == '1')
		return (get_wall(mlx->map, mlx->ref, row, col));
	else if (mlx->map[row][col] == 'C')
		return (get_obj_sprite(mlx, mlx->gp.coll, row, col));
	else if (mlx->map[row][col] == 'E')
		return (get_obj_sprite(mlx, mlx->gp.exits, row, col));
	else if (mlx->map[row][col] == 'P')
	{
		if (mlx->gp.mobs_count == NOT_BONUS)
			return (mlx->gp.pj.pj_idle->img);
		return (get_anim(&mlx->gp.pj.pj_idle, ANIM_PJ));
	}
	else if (mlx->map[row][col] == 'M')
		return (get_mob(ANIM_MOB, col, row, mlx->gp.mobs));
	return (mlx->ref.bad);
}

t_img	get_mob(int max_time, int x, int y, t_mob *mobs)
{
	int		timer;

	timer = 50;
	while (mobs->pos.y != y && mobs->pos.x != x)
		mobs = mobs->next;
	if (mobs->wait < timer)
		mobs->wait++;
	else
	{
		mobs->wait = 0;
		mobs->pos.y += mobs->dir.y;
		mobs->pos.x += mobs->dir.x;
	}
	return (get_anim(&mobs->anim, max_time));
}

t_img	get_anim(t_anim **anim, int max_time)
{
	struct timeval	current;
	long int		playing_time;

	gettimeofday(&current, NULL);
	playing_time = ((current.tv_sec - (*anim)->played.tv_sec) * 1000)
		- ((current.tv_usec - (*anim)->played.tv_usec) / 1000);
	if (playing_time >= max_time)
	{
		(*anim) = (*anim)->next;
		(*anim)->played = current;
	}
	// else
		// (*anim)->played++;
	return ((*anim)->img);
}
