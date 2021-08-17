/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:29:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/17 18:20:31 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

char	*get_wall(char **map, t_textures *textures, int row, int col)
{
	if (col == 0 && row == 0)
		return (textures->wall_corner_nw);
	else if (col == ft_strlen(map[row]) - 1 && row == 0)
		return (textures->wall_corner_ne);
	else if (col > 0 &&  col < ft_strlen(map[row]) - 1 && row == 0)
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
		return (get_wall(mlx->map->map, mlx->textures, row, col));
	else if (mlx->map->map[row][col] == 'C')
		return (get_animation(&mlx->textures->obj, 1));
	else if (mlx->map->map[row][col] == 'E')
		return (get_animation(&mlx->textures->exit, 2));
	else if (mlx->map->map[row][col] == 'P')
		return (get_animation(&mlx->textures->pj_idle, 0));
	return (NULL);
}

char	*get_animation(t_anim **anim, int play_time)
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
