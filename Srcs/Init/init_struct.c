/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:08:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/30 13:02:30 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	// my_mlx->rev_print = 0;
	my_mlx->gp = init_gameplay();
	my_mlx->time.tv_sec = 0;
	my_mlx->time.tv_usec = 0;
	my_mlx->pxl_img = -1;
	my_mlx->map = NULL;
	return (my_mlx);
}

t_img	init_img(void)
{
	t_img	img;

	img.img = NULL;
	img.addr = NULL;
	img.bits_pxl = 0;
	img.line_len = 0;
	img.endian = 0;
	img.width = 100;
	img.height = 100;
	img.rev_print = 0;
	return (img);
}

t_player	init_player(void)
{
	t_player	pj;

	pj.moves = 0;
	pj.pj_moved = 0;
	pj.pj_pos.y = -1;
	pj.pj_pos.x = -1;
	pj.pj_idle = NULL;
	return (pj);
}

t_gp	init_gameplay(void)
{
	t_gp	gp;

	gp.pj = init_player();
	gp.mobs_count = -1;
	gp.mobs = NULL;
	gp.coll.count = 0;
	gp.coll.path =  "./Sprites/Objects/Flowers/";
	gp.coll.sprites = 4;
	gp.coll.pos = NULL;
	gp.exits.count = 0;
	gp.exits.path =  "./Sprites/Exit/Typhoon/";
	gp.exits.sprites = 2;
	gp.exits.pos = NULL;
	return (gp);
}
