/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:17:06 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/15 16:36:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	init_window(t_mlx_vars *mlx, int bonus)
{
	if (mlx->ref)
		free_sprites(mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->img->width,
			mlx->img->height, "so_long");
	mlx->img->img = mlx_new_image(mlx->mlx, mlx->img->width, mlx->img->height);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_pxl,
			&mlx->img->line_len, &mlx->img->endian);
	mlx->ref = init_refs_paths(mlx, bonus);
	return ;
}

int	mlx_check_size_window(t_mlx_vars *mlx)
{
	int		changed;
	int		screen_x;
	int		screen_y;

	changed = 0;
	mlx_get_screen_size(mlx->mlx, &screen_x, &screen_y);
	if (mlx->map->pxl_img * ft_strlen((const char *)mlx->map->map[0]) > screen_x)
		return (-1);
	while ((mlx->map->pxl_img * ft_strlen((const char *)mlx->map->map[0]))
		> mlx->img->width)
	{
		changed = 1;
		mlx->img->width = mlx->img->width * 2;
	}
	while ((mlx->map->pxl_img * ft_tablen((const char **)mlx->map->map))
		> mlx->img->height)
	{
		changed = 1;
		mlx->img->height = mlx->img->height * 3;
	}
	return (changed);
}
