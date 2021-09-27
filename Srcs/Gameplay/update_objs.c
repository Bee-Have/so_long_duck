/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:06:26 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/27 12:47:33 by amarini-         ###   ########.fr       */
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
		if (mlx->map[pos.y][pos.x] == '0')
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
	t_objs	*new;
	int		i_old;
	int		i_new;
	int		len;

	i_old = 0;
	i_new = 0;
	len = mlx->gp.coll.count - 1;
	new = (t_objs *)malloc(len * sizeof(t_objs));
	if (!new)
		return ;
	while (i_old < mlx->gp.coll.count)
	{
		if (mlx->gp.coll.obj[i_old].pos.y == pos.y
			&& mlx->gp.coll.obj[i_old].pos.x == pos.x)
		{
			mlx->gp.coll.obj[i_old].pos.y = -1;
			mlx->gp.coll.obj[i_old].pos.x = -1;
		}
		else
		{
			new[i_new] = mlx->gp.coll.obj[i_old];
			++i_new;
		}
		++i_old;
	}
	free(mlx->gp.coll.obj);
	mlx->gp.coll.obj = new;
	--mlx->gp.coll.count;
	return ;
}
