/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:18:10 by user42            #+#    #+#             */
/*   Updated: 2021/11/02 21:22:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

// int	check_1ce(t_mlx_vars *mlx, t_vec2 pos)
// {
	// if ()
// }
