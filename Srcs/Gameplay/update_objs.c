/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:06:26 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/24 16:53:38 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_objs(t_mlx_vars *mlx)
{
	int		i;
	t_vec2	pos;

	i = 0;
	while (i < mlx->gp.exits.count)
	{
		pos = mlx->gp.exits.obj[i].pos;
		if (mlx->map[pos.y][pos.x] == '0')
			mlx->map[pos.y][pos.x] = 'E';
		++i;
	}
	i = 0;
	while (i < mlx->gp.coll.count)
	{
		pos = mlx->gp.coll.obj[i].pos;
		if (pos.x != -1 && pos.y != -1 && mlx->map[pos.y][pos.x] == '0')
			mlx->map[pos.y][pos.x] = 'C';
		++i;
	}
	return ;
}

t_img	get_obj_sprite(t_mlx_vars *mlx, t_objs_parent parent, int y, int x)
{
	int		i;

	i = 0;
	while (i < parent.count)
	{
		if (parent.obj[i].pos.y == y && parent.obj[i].pos.x == x)
			return (get_anim(&parent.obj[i].anim, 15));
		++i;
	}
	return (mlx->ref.bad);
}

void	delete_collectible(t_mlx_vars *mlx, t_vec2 pos)
{
	int		i;
	t_objs	coll;

	i = 0;
	while (i < mlx->gp.coll.count)
	{
		coll = mlx->gp.coll.obj[i];
		if (coll.pos.y == pos.y && coll.pos.y == pos.y)
		{
			coll.pos.y = -1;
			coll.pos.x = -1;
		}
		++i;
	}
	--mlx->gp.coll.count;
	return ;
}
