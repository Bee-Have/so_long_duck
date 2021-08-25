/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:08:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/25 18:27:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_mlx_vars	*init_mlx_struct(void)
{
	t_mlx_vars	*my_mlx;

	my_mlx = NULL;
	my_mlx = (t_mlx_vars *)malloc(sizeof(t_mlx_vars));
	if (!my_mlx)
		return (NULL);
	my_mlx->mlx = mlx_init();
	my_mlx->mlx_win = NULL;
	my_mlx->img = init_img();
	my_mlx->map = init_map();
	my_mlx->mobs_count = -1;
	my_mlx->mobs = NULL;
	my_mlx->ref = NULL;
	return (my_mlx);
}

t_img	*init_img(void)
{
	t_img	*img;

	img = NULL;
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = NULL;
	img->addr = NULL;
	img->bits_pxl = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 100;
	img->height = 100;
	return (img);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = NULL;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->moves = 0;
	map->pj_moved = 0;
	map->pj_pos[0] = -1;
	map->pj_pos[1] = -1;
	map->pxl_img = -1;
	return (map);
}

t_refs	*init_refs_paths(t_mlx_vars *mlx)
{
	t_refs	*ref;

	ref = NULL;
	ref = (t_refs *)malloc(sizeof(t_refs));
	if (!ref)
		return (NULL);
	ref->wall = get_addr(mlx, "./Sprites/Walls/Pond/wall.xpm");
	ref->wall_n = get_addr(mlx, "./Sprites/Walls/Pond/wall_n.xpm");
	ref->wall_s = get_addr(mlx, "./Sprites/Walls/Pond/wall_s.xpm");
	ref->wall_e = get_addr(mlx, "./Sprites/Walls/Pond/wall_e.xpm");
	ref->wall_w = get_addr(mlx, "./Sprites/Walls/Pond/wall_w.xpm");
	ref->wall_corner_ne = get_addr(mlx, "./Sprites/Walls/Pond/wall_ne.xpm");
	ref->wall_corner_nw = get_addr(mlx, "./Sprites/Walls/Pond/wall_nw.xpm");
	ref->wall_corner_se = get_addr(mlx, "./Sprites/Walls/Pond/wall_se.xpm");
	ref->wall_corner_sw = get_addr(mlx, "./Sprites/Walls/Pond/wall_sw.xpm");
	ref->tile = init_anim(mlx, 4, "./Sprites/Floor_Tiles/");
	ref->obj = init_anim(mlx, 4, "./Sprites/Objects/Flowers/");
	ref->exit = init_anim(mlx, 2, "./Sprites/Exit/Typhoon/");
	ref->pj_idle = init_anim(mlx, 5, "./Sprites/Characters/Frog/Idle/");
	return (ref);
}
