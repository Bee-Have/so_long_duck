/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:25:35 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/27 16:09:51 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

#ifdef __unix__
static const int	g_W = 119;
static const int	g_A = 97;
static const int	g_S = 115;
static const int	g_D = 100;
static const int	g_ESC = 65307;
#elif __APPLE__
static const int	g_W = 13;
static const int	g_A = 0;
static const int	g_S = 1;
static const int	g_D = 2;
static const int	g_ESC = 53;
#endif

int	key_hook(int keycode, t_mlx_vars *mlx)
{
	if (keycode == g_ESC)
	{
		close_g_windog_w(mlx);
		return (-1);
	}
	if (mlx->map->pj_moved == 0)
	{
		if (keycode == g_W && mlx->map->pj_pos[0] > 0)
			mlx->map->pj_pos[0] -= 1;
		if (keycode == g_S
			&& mlx->map->pj_pos[0] < ft_tablen((const char **)mlx->map->map))
			mlx->map->pj_pos[0] += 1;
		if (keycode == g_A && mlx->map->pj_pos[1] > 0)
			mlx->map->pj_pos[1] -= 1;
		if (keycode == g_D
			&& mlx->map->pj_pos[1] < ft_strlen((const char *)mlx->map->map[0]))
			mlx->map->pj_pos[1] += 1;
		mlx->map->pj_moved = 1;
	}
	return (0);
}

int	close_g_windog_w(t_mlx_vars *mlx)
{
	free_manager(mlx);
	return (1);
}
