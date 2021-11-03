/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:18:10 by user42            #+#    #+#             */
/*   Updated: 2021/11/03 11:17:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_1cepm(t_mlx_vars *mlx, t_vec2 pos, int print)
{
	if (print == PRINT_1CE)
	{
		if (mlx->map[pos.y][pos.x] == '1'
			|| check_for_obj(mlx->gp.coll, pos) == 1
			|| check_for_obj(mlx->gp.exits, pos) == 1)
			return (1);
	}
	else if (print == PRINT_PM)
	{
		if (mlx->map[pos.y][pos.x] == 'P' || mlx->map[pos.y][pos.x] == 'M')
			return (2);
	}
	return (0);
}

int	check_for_obj(t_objs_parent obj, t_vec2 pos)
{
	int	i;

	i = 0;
	while (i < obj.count)
	{
		if (obj.pos[i].y == pos.y && obj.pos[i].x == pos.x)
			return (1);
		++i;
	}
	return (0);
}
