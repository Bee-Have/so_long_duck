/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:08:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/05 15:42:49 by amarini-         ###   ########.fr       */
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
	
	map_info->wall_n = "./Sprites/Walls/Pond/t_wall_tile.xpm";
	map_info->wall_s = "./Sprites/Walls/Pond/b_wall_tile.xpm";
	map_info->wall_e = "./Sprites/Walls/Pond/r_wall_tile.xpm";
	map_info->wall_w = "./Sprites/Walls/Pond/l_wall_tile.xpm";
	map_info->wall_corner_ne = "./Sprites/Walls/Pond/t_corner_r.xpm";
	map_info->wall_corner_nw = "./Sprites/Walls/Pond/t_corner_l.xpm";
	map_info->wall_corner_se = "./Sprites/Walls/Pond/b_corner_r.xpm";
	map_info->wall_corner_sw = "./Sprites/Walls/Pond/b_corner_l.xpm";
	
	map_info->exit = "./Sprites/Exit/exit_0.xpm";
	map_info->obj = "./Sprites/Objects/rocks.xpm";
	
	map_info->pj = "./Sprites/Characters/Frog/Idle/0.xpm";
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
	my_mlx->width = 1920;
	my_mlx->height = 1080;
	return (my_mlx);
}