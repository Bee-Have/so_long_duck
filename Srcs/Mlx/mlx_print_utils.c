/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:17:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/12 15:50:16 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	calc_offset(int pxl, int map_len, int max_win)
{
	int		offset;
	int		max_pxl_win;
	int		midd_pxl;

	midd_pxl = (pxl * map_len) / 2;
	max_pxl_win = pxl * map_len;
	offset = (max_win - max_pxl_win) / 2;
	return (offset);
}

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
		mlx->textures->exit = mlx->textures->exit->next;
		return (mlx->textures->exit->prev->img);
	}
	else if (mlx->map->map[row][col] == 'P')
	{
		mlx->textures->pj_idle = mlx->textures->pj_idle->next;
		return (mlx->textures->pj_idle->prev->img);
	}
	return (NULL);
}
