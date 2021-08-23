/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:29:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/23 20:36:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

char	*get_wall(char **map, t_refs *textures, int row, int col)
{
	if (col == 0 && row == 0)
		return (textures->wall_corner_nw);
	else if (col == ft_strlen(map[row]) - 1 && row == 0)
		return (textures->wall_corner_ne);
	else if (col > 0 && col < ft_strlen(map[row]) - 1 && row == 0)
		return (textures->wall_n);
	else if (col == 0 && row == ft_tablen((const char **)map) - 1)
		return (textures->wall_corner_sw);
	else if (col == ft_strlen(map[row]) - 1
		&& row == ft_tablen((const char **)map) - 1)
		return (textures->wall_corner_se);
	else if (col > 0 && col < ft_strlen(map[row]) - 1
		&& row == ft_tablen((const char **)map) - 1 )
		return (textures->wall_s);
	else if (col == 0 && row > 0 && row < ft_tablen((const char **)map) - 1)
		return (textures->wall_w);
	else if (col == ft_strlen(map[row]) - 1 && row > 0
		&& row < ft_tablen((const char **)map) - 1)
		return (textures->wall_e);
	return (textures->wall);
}

char	*get_right_xpm(t_mlx_vars *mlx, int row, int col)
{
	if (mlx->map->map[row][col] == '1')
		return (get_wall(mlx->map->map, mlx->ref, row, col));
	else if (mlx->map->map[row][col] == 'C')
		return (get_anim(&mlx->ref->obj, 2));
	else if (mlx->map->map[row][col] == 'E')
		return (get_anim(&mlx->ref->exit, 2));
	else if (mlx->map->map[row][col] == 'P')
		return (get_anim(&mlx->ref->pj_idle, 1));
	else if (mlx->map->map[row][col] == 'M')
		
	return (NULL);
}

char	*get_anim(t_anim **anim, int play_time)
{
	if ((*anim)->played >= play_time)
	{
		(*anim)->played = 0;
		(*anim) = (*anim)->next;
	}
	else
		(*anim)->played++;
	return ((*anim)->img);
}
