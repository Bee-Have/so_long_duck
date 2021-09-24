/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:47:30 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/24 18:46:12 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_refs	init_refs_paths(t_mlx_vars *mlx)
{
	t_refs	ref;

	ref.bad = make_img(mlx, "./Sprites/Error/bad.xpm");
	ref.wall = make_img(mlx, "./Sprites/Walls/Pond/wall.xpm");
	ref.wall_n = make_img(mlx, "./Sprites/Walls/Pond/wall_n.xpm");
	ref.wall_s = make_img(mlx, "./Sprites/Walls/Pond/wall_s.xpm");
	ref.wall_e = make_img(mlx, "./Sprites/Walls/Pond/wall_e.xpm");
	ref.wall_w = make_img(mlx, "./Sprites/Walls/Pond/wall_w.xpm");
	ref.wall_corner_ne = make_img(mlx, "./Sprites/Walls/Pond/wall_ne.xpm");
	ref.wall_corner_nw = make_img(mlx, "./Sprites/Walls/Pond/wall_nw.xpm");
	ref.wall_corner_se = make_img(mlx, "./Sprites/Walls/Pond/wall_se.xpm");
	ref.wall_corner_sw = make_img(mlx, "./Sprites/Walls/Pond/wall_sw.xpm");
	init_refs_anims(mlx, &ref);
	return (ref);
}

void	init_refs_anims(t_mlx_vars *mlx, t_refs *ref)
{
	if (mlx->gp.mobs_count > NOT_BONUS)
	{
		(*ref).tile = init_anim(mlx, 4, "./Sprites/Floor_Tiles/");
		mlx->gp.pj.pj_idle = init_anim(mlx, 5
			, "./Sprites/Characters/Frog/Idle/");
	}
	else
	{
		(*ref).tile = init_anim(mlx, 0, "./Sprites/Floor_Tiles/");
		mlx->gp.coll.sprites = 0;
		mlx->gp.exits.sprites = 0;
		mlx->gp.pj.pj_idle = init_anim(mlx, 0
			, "./Sprites/Characters/Frog/Idle/");
	}
	return ;
}

t_img	make_img(t_mlx_vars *mlx, char *path)
{
	t_img	sprite;
	int		size;

	sprite = init_img();
	sprite.img = mlx_xpm_file_to_image(mlx->mlx, path, &size, &size);
	if (mlx->pxl_img == -1)
		mlx->pxl_img = size;
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_pxl,
			&sprite.line_len, &sprite.endian);
	size = sprite.line_len * 36;
	black_to_transparency(sprite.addr, size);
	return (sprite);
}
