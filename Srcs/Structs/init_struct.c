/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:08:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/06 17:45:52 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_map_info	*init_map_info(void)
{
	t_map_info	*map_info;
	
	map_info = NULL;
	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (!map_info)
		return (NULL);
	map_info->map = NULL;
	map_info->floor = "./Sprites/Floor_Tiles/water_tile_2.xpm";
	map_info->wall = "./Sprites/Walls/Pond/wall.xpm";
	map_info->wall_n = "./Sprites/Walls/Pond/wall_n.xpm";
	map_info->wall_s = "./Sprites/Walls/Pond/wall_s.xpm";
	map_info->wall_e = "./Sprites/Walls/Pond/wall_e.xpm";
	map_info->wall_w = "./Sprites/Walls/Pond/wall_w.xpm";
	map_info->wall_corner_ne = "./Sprites/Walls/Pond/wall_ne.xpm";
	map_info->wall_corner_nw = "./Sprites/Walls/Pond/wall_nw.xpm";
	map_info->wall_corner_se = "./Sprites/Walls/Pond/wall_se.xpm";
	map_info->wall_corner_sw = "./Sprites/Walls/Pond/wall_sw.xpm";
	map_info->exit = "./Sprites/Exit/exit_0.xpm";
	map_info->obj = "./Sprites/Objects/rocks.xpm";
	map_info->pj = "./Sprites/Characters/Frog/Idle/0.xpm";
	map_info->x_pxl_img = 0;
	map_info->y_pxl_img = 0;
	return (map_info);
}

t_mlx_vars	*init_mlx_struct(void)
{
	t_mlx_vars	*my_mlx;

	my_mlx = NULL;
	my_mlx = (t_mlx_vars *)malloc(sizeof(t_mlx_vars));
	if (!my_mlx)
		return (NULL);
	my_mlx->mlx = mlx_init();
	my_mlx->mlx_win = NULL;
	my_mlx->img = NULL;
	my_mlx->bits_pix = 0;
	my_mlx->line_length = 0;
	my_mlx->endian = 0;
	my_mlx->pxl_x = 0;
	my_mlx->pxl_y = 0;
	my_mlx->width = 500;
	my_mlx->height = 500;
	return (my_mlx);
}