/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:56:56 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/22 11:33:15 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	print_manager(t_mlx_vars *mlx)
{
	char	*moves;
	char	*coll;
	char	*tmp;
	int		x;
	int		y;

	moves = ft_itoa(mlx->map->moves);
	tmp = ft_itoa(mlx->c);
	coll = ft_strjoin("Collectibles : ", tmp);
	x = mlx->img->width / 2;
	y = offset(mlx->map->pxl_img, ft_tablen((const char **)mlx->map->map) + 1,
			mlx->img->height);
	mlx_string_put(mlx->mlx, mlx->mlx_win, x, y, 0x00F8FFFA, moves);
	x = offset(mlx->map->pxl_img, ft_strlen(mlx->map->map[0]),
			mlx->img->width);
	mlx_string_put(mlx->mlx, mlx->mlx_win, x - 4, y, 0x00F8FFFA, coll);
	free(moves);
	free(tmp);
	free(coll);
}

void	print_manager_console(int moves)
{
	char	*tmp;
	char	*final;

	tmp = ft_itoa(moves);
	final = ft_strjoin(tmp, "\r");
	ft_putstr(final);
	free(tmp);
	free(final);
}
