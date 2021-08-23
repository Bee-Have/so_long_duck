/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:25:35 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/20 14:53:23 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	key_hook(int keycode, t_mlx_vars *mlx)
{
	if (keycode == 53)
	{
		close_window(mlx);
		return (-1);
	}
	if (mlx->map->pj_moved == 0)
	{
		if (keycode == 13 && mlx->map->pj_pos[0] > 0)
			mlx->map->pj_pos[0] -= 1;
		if (keycode == 1
			&& mlx->map->pj_pos[0] < ft_tablen((const char **)mlx->map->map))
			mlx->map->pj_pos[0] += 1;
		if (keycode == 0 && mlx->map->pj_pos[1] > 0)
			mlx->map->pj_pos[1] -= 1;
		if (keycode == 2
			&& mlx->map->pj_pos[1] < ft_strlen((const char *)mlx->map->map[0]))
			mlx->map->pj_pos[1] += 1;
		mlx->map->pj_moved = 1;
	}
	return (0);
}

int	close_window(t_mlx_vars *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(1);
	return (1);
}
