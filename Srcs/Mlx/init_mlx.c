/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:17:06 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/11 14:45:05 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	init_window(t_mlx_vars *mlx)
{
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->width
			, mlx->height, "so_long");
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_pix,
			&mlx->line_length, &mlx->endian);
	return ;
}

int	mlx_check_size_window(t_mlx_vars *mlx)
{
	int		changed;

	changed = 0;
	while ((mlx->map->pxl_img * ft_strlen((const char *)mlx->map->map[0]))
		> mlx->width)
	{
		changed = 1;
		mlx->width = mlx->width * 2;
	}
	while ((mlx->map->pxl_img * ft_tablen((const char **)mlx->map->map))
		> mlx->height)
	{
		changed = 1;
		mlx->height = mlx->height * 2;
	}
	return (changed);
}
