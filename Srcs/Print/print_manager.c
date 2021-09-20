/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:56:52 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/20 13:06:43 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	print_manager(t_mlx_vars *mlx)
{
	char	*moves;
	char	*coll;
	int		x;
	int		y;

	moves = ft_itoa(mlx->map->moves);
	coll = ft_itoa(mlx->c_count);
	x = mlx->img->width / 2;
	y = offset(mlx->map->pxl_img,
			ft_tablen((const char **)mlx->map->map) + 1, mlx->img->height);
	mlx_string_put(mlx->mlx, mlx->mlx_win, x, y, 0x00F8FFFA, moves);
	x = offset(mlx->map->pxl_img, ft_strlen(mlx->map->map[0]) + 1
		, mlx->img->width);
	mlx_string_put(mlx->mlx, mlx->mlx_win, x, y, 0x00F8FFFA, coll);
	free(moves);
	free(coll);
}
