/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_1cepm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:26:11 by amarini-          #+#    #+#             */
/*   Updated: 2021/11/04 17:28:12 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	get_1cepm_xpm(t_mlx_vars *mlx, t_vec2 pos, int print)
{
	if (check_1cepm(mlx, pos, print) == PRINT_1CE)
		return (get_1ce_xpm(mlx, pos));
	else if (check_1cepm(mlx, pos, print) == PRINT_PM)
		return (get_pm_xpm(mlx, pos));
	return (get_all_xpm(mlx, pos));
}

t_img	get_all_xpm(t_mlx_vars *mlx, t_vec2 pos)
{
	if (mlx->map[pos.y][pos.x] == '1')
		return (get_wall(mlx->map, mlx->ref, pos.y, pos.x));
	else if (mlx->map[pos.y][pos.x] == 'C')
	{
		if (mlx->gp.mobs_count == NOT_BONUS)
			return (mlx->gp.coll.anim->img);
		return (get_anim(&mlx->gp.coll.anim, ANIM_COLL, mlx->time));
	}
	else if (mlx->map[pos.y][pos.x] == 'E')
	{
		if (mlx->gp.mobs_count == NOT_BONUS)
			return (mlx->gp.exits.anim->img);
		return (get_anim(&mlx->gp.exits.anim, ANIM_EXIT, mlx->time));
	}
	if (mlx->map[pos.y][pos.x] == 'P')
	{
		if (mlx->gp.mobs_count == NOT_BONUS)
			return (mlx->gp.pj.pj_idle->img);
		return (get_anim(&mlx->gp.pj.pj_idle, ANIM_PJ, mlx->time));
	}
	else if (mlx->map[pos.y][pos.x] == 'M')
		return (get_mob(mlx, pos.y, pos.x));
	return (mlx->ref.bad);
}

t_img	get_1ce_xpm(t_mlx_vars *mlx, t_vec2 pos)
{
	if (mlx->map[pos.y][pos.x] == '1')
		return (get_wall(mlx->map, mlx->ref, pos.y, pos.x));
	else if (mlx->map[pos.y][pos.x] == 'C'
			|| check_for_obj(mlx->gp.coll, pos) == 1)
	{
		if (mlx->gp.mobs_count == NOT_BONUS)
			return (mlx->gp.coll.anim->img);
		return (get_anim(&mlx->gp.coll.anim, ANIM_COLL, mlx->time));
	}
	else if (mlx->map[pos.y][pos.x] == 'E'
			|| check_for_obj(mlx->gp.exits, pos) == 1)
	{
		if (mlx->gp.mobs_count == NOT_BONUS)
			return (mlx->gp.exits.anim->img);
		return (get_anim(&mlx->gp.exits.anim, ANIM_EXIT, mlx->time));
	}
	return (mlx->ref.bad);
}

t_img	get_pm_xpm(t_mlx_vars *mlx, t_vec2 pos)
{
	if (mlx->map[pos.y][pos.x] == 'P')
	{
		if (mlx->gp.mobs_count == NOT_BONUS)
			return (mlx->gp.pj.pj_idle->img);
		return (get_anim(&mlx->gp.pj.pj_idle, ANIM_PJ, mlx->time));
	}
	else if (mlx->map[pos.y][pos.x] == 'M')
		return (get_mob(mlx, pos.y, pos.x));
	return (mlx->ref.bad);
}
