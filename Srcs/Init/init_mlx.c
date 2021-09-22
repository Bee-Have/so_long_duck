/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:17:06 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/22 12:53:19 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	changed = 0;
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
