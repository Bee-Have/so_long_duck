/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:56:56 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/21 11:22:52 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	print_manager(t_mlx_vars *mlx)
{
	char	*moves;
	int		x;
	int		y;

	moves = ft_itoa(mlx->map->moves);
	x = mlx->img->width / 2;
	y = offset(mlx->map->pxl_img,
			ft_tablen((const char **)mlx->map->map) + 1, mlx->img->height);
	mlx_string_put(mlx->mlx, mlx->mlx_win, x, y, 0x00F8FFFA, moves);
	free(moves);
}

void	print_moves(int moves)
{
	char	*tmp;
	char	*final;

	tmp = ft_itoa(moves);
	final = ft_strjoin(tmp, "\r");
	ft_putstr(final);
	free(tmp);
	free(final);
}
