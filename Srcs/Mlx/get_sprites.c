/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:29:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/10/01 12:51:55 by user42           ###   ########.fr       */
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
	{
		if (mlx->gp.mobs_count == NOT_BONUS)
			return (mlx->gp.coll.anim->img);
		return (get_anim(&mlx->gp.coll.anim, ANIM_COLL, mlx->time));
	}
	else if (mlx->map[row][col] == 'E')
	{
		if (mlx->gp.mobs_count == NOT_BONUS)
			return (mlx->gp.exits.anim->img);
		return (get_anim(&mlx->gp.exits.anim, ANIM_EXIT, mlx->time));
	}
	else if (mlx->map[row][col] == 'P')
	{
		if (mlx->gp.mobs_count == NOT_BONUS)
			return (mlx->gp.pj.pj_idle->img);
		return (get_anim(&mlx->gp.pj.pj_idle, ANIM_PJ, mlx->time));
	}
	else if (mlx->map[row][col] == 'M')
		return (get_mob(mlx, row, col));
	return (mlx->ref.bad);
}

t_img	get_mob(t_mlx_vars *mlx, int y, int x)
{
	t_img		result;
	long int	timer;

	while (mlx->gp.mobs->pos.y != y && mlx->gp.mobs->pos.x != x)
		mlx->gp.mobs = mlx->gp.mobs->next;
	timer = ((mlx->time.tv_sec - mlx->gp.mobs->wait.tv_sec) * 1000)
		+ ((mlx->time.tv_usec - mlx->gp.mobs->wait.tv_usec) / 1000);
	if (timer > MOVE_MOB)
	{
		mlx->gp.mobs->wait = mlx->time;
		mlx->gp.mobs->pos.y += mlx->gp.mobs->dir.y;
		mlx->gp.mobs->pos.x += mlx->gp.mobs->dir.x;
	}
	result = get_anim(&mlx->gp.anim_mob, ANIM_MOB, mlx->time);
	if (mlx->gp.mobs->dir.x == 1)
		result.rev_print = 1;
	else
		result.rev_print = 0;
	return (result);
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
