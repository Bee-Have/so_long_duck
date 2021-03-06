/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:25:35 by amarini-          #+#    #+#             */
/*   Updated: 2021/10/25 11:15:34 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifdef __unix__

static const int	g_w = 119;
static const int	g_a = 97;
static const int	g_s = 115;
static const int	g_d = 100;
static const int	g_esc = 65307;
#elif __APPLE__

static const int	g_w = 13;
static const int	g_a = 0;
static const int	g_s = 1;
static const int	g_d = 2;
static const int	g_esc = 53;
#endif

int	key_hook(int keycode, t_mlx_vars *mlx)
{
	if (keycode == g_esc)
		close_window(mlx);
	if (mlx->gp.pj.pj_moved == 0)
	{
		if (keycode == g_w && mlx->gp.pj.pj_pos.y > 0)
			mlx->gp.pj.pj_pos.y -= 1;
		if (keycode == g_s
			&& mlx->gp.pj.pj_pos.y < ft_tablen((const char **)mlx->map))
			mlx->gp.pj.pj_pos.y += 1;
		if (keycode == g_a && mlx->gp.pj.pj_pos.x > 0)
		{
			rev_anim(&mlx->gp.pj.pj_idle, 1);
			mlx->gp.pj.pj_pos.x -= 1;
		}
		if (keycode == g_d
			&& mlx->gp.pj.pj_pos.x < ft_strlen((const char *)mlx->map[0]))
		{
			if (mlx->gp.pj.pj_idle->img.rev_print == 1)
				rev_anim(&mlx->gp.pj.pj_idle, 0);
			mlx->gp.pj.pj_pos.x += 1;
		}
		mlx->gp.pj.pj_moved = 1;
	}
	return (0);
}

int	close_window(t_mlx_vars *mlx)
{
	free_manager(mlx, 1);
	return (1);
}
