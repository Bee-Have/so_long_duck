/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:06:26 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/27 17:14:07 by amarini-         ###   ########.fr       */
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
		pos = mlx->gp.exits.pos[i];
		if (mlx->map[pos.y][pos.x] == '0')
			mlx->map[pos.y][pos.x] = 'E';
		++i;
	}
	i = 0;
	while (i < mlx->gp.coll.count)
	{
		pos = mlx->gp.coll.pos[i];
		if (mlx->map[pos.y][pos.x] == '0')
			mlx->map[pos.y][pos.x] = 'C';
		++i;
	}
	return ;
}

// t_img	get_obj_sprite(t_mlx_vars *mlx, t_objs_parent parent, int y, int x)
// {
// 	int		i;

// 	i = 0;
// 	while (i < parent.count)
// 	{
// 		if (parent.pos[i].y == y && parent.pos[i].x == x)
// 		{
// 			if (mlx->gp.mobs_count == NOT_BONUS)
// 				return (parent.obj[i].anim->img);
// 			return (get_anim(&parent.obj[i].anim, ANIM_OBJS));
// 		}
// 		++i;
// 	}
// 	return (mlx->ref.bad);
// }

void	delete_collectible(t_mlx_vars *mlx, t_vec2 pos)
{
	t_vec2	*new;
	int		i_old;
	int		i_new;
	int		len;

	i_old = 0;
	i_new = 0;
	len = mlx->gp.coll.count - 1;
	new = (t_vec2 *)malloc(len * sizeof(t_vec2));
	if (!new)
		return ;
	while (i_old < mlx->gp.coll.count)
	{
		if (mlx->gp.coll.pos[i_old].y == pos.y
			&& mlx->gp.coll.pos[i_old].x == pos.x)
		{
			mlx->gp.coll.pos[i_old].y = -1;
			mlx->gp.coll.pos[i_old].x = -1;
		}
		else
		{
			new[i_new] = mlx->gp.coll.pos[i_old];
			++i_new;
		}
		++i_old;
	}
	free(mlx->gp.coll.pos);
	mlx->gp.coll.pos = new;
	--mlx->gp.coll.count;
	return ;
}
