/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:08:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/31 18:11:15 by amarini-         ###   ########.fr       */
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
