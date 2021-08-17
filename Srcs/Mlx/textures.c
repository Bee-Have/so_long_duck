/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:29:57 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/17 12:34:48 by amarini-         ###   ########.fr       */
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
		return (mlx->textures->obj);
	else if (mlx->map->map[row][col] == 'E')
	{
		if (mlx->textures->exit->played == 4)
		{
			mlx->textures->exit->played = 0;
			mlx->textures->exit = mlx->textures->exit->next;
		}
		else
			mlx->textures->exit->played++;
		return (mlx->textures->exit->prev->img);
	}
	else if (mlx->map->map[row][col] == 'P')
	{
		if (mlx->textures->pj_idle->played == 2)
		{
			mlx->textures->pj_idle->played = 0;
			mlx->textures->pj_idle = mlx->textures->pj_idle->next;
		}
		else
			mlx->textures->pj_idle->played++;
		return (mlx->textures->pj_idle->prev->img);
	}
	return (NULL);
}

char	*get_animation(t_mlx_vars *mlx, int row, int col)
{
	
}
