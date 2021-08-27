/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:25:35 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/27 15:32:38 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

#ifdef __unix__
static const int W = 119;
static const int A = 97;
static const int S = 115;
static const int D = 100;
static const int ESC = 65307;
#elif __APPLE__
static const int W = 13;
static const int A = 0;
static const int S = 1;
static const int D = 2;
static const int ESC = 53;
#endif

int	key_hook(int keycode, t_mlx_vars *mlx)
{
	if (keycode == ESC)
	{
		close_window(mlx);
		return (-1);
	}
	if (mlx->map->pj_moved == 0)
	{
		if (keycode == W && mlx->map->pj_pos[0] > 0)
			mlx->map->pj_pos[0] -= 1;
		if (keycode == S
			&& mlx->map->pj_pos[0] < ft_tablen((const char **)mlx->map->map))
			mlx->map->pj_pos[0] += 1;
		if (keycode == A && mlx->map->pj_pos[1] > 0)
			mlx->map->pj_pos[1] -= 1;
		if (keycode == D
			&& mlx->map->pj_pos[1] < ft_strlen((const char *)mlx->map->map[0]))
			mlx->map->pj_pos[1] += 1;
		mlx->map->pj_moved = 1;
	}
	return (0);
}

int	close_window(t_mlx_vars *mlx)
{
	free_manager(mlx);
}
