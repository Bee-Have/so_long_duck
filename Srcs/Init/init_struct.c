/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:08:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/23 12:40:29 by amarini-         ###   ########.fr       */
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
	my_mlx->gp = init_gameplay();
	my_mlx->pxl_img = -1;
	my_mlx->map = NULL;
	// my_mlx->ref = NULL;
	return (my_mlx);
}

t_img	init_img(void)
{
	t_img	img;

	// img = NULL;
	// img = malloc(sizeof(t_img));
	// if (!img)
		// return (NULL);
	img.img = NULL;
	img.addr = NULL;
	img.bits_pxl = 0;
	img.line_len = 0;
	img.endian = 0;
	img.width = 100;
	img.height = 100;
	return (img);
}

//add fuction to init PJ
t_player	init_player(void)
{
	t_player	pj;

	pj.moves = 0;
	pj.pj_moved = 0;
	pj.pj_pos[0] = -1;
	pj.pj_pos[1] = -1;
	pj.pj_idle = NULL;
	return (pj);
}
//add fuction to init EXITS
//	exits will be updated post parsing
//add fuction to init COLLECTIBLES
//	same for collectibles

t_gp	init_gameplay(void)
{
	t_gp	gp;

	// gp = malloc(sizeof(t_gp));
	// if (!gp)
		// return (NULL);
	gp.mobs_count = -1;
	gp.mobs = NULL;
	gp.c_count = 0;
	gp.coll = NULL;
	gp.e_count = 0;
	gp.exits = NULL;
	return (gp);
}
