/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:08:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/19 13:31:47 by amarini-         ###   ########.fr       */
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
	my_mlx->ref = init_refs_paths();
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

t_refs	*init_refs_paths(void)
{
	t_refs	*ref;

	ref = NULL;
	ref = (t_refs *)malloc(sizeof(t_refs));
	if (!ref)
		return (NULL);
	ref->wall = "./Sprites/Walls/Pond/wall.xpm";
	ref->wall_n = "./Sprites/Walls/Pond/wall_n.xpm";
	ref->wall_s = "./Sprites/Walls/Pond/wall_s.xpm";
	ref->wall_e = "./Sprites/Walls/Pond/wall_e.xpm";
	ref->wall_w = "./Sprites/Walls/Pond/wall_w.xpm";
	ref->wall_corner_ne = "./Sprites/Walls/Pond/wall_ne.xpm";
	ref->wall_corner_nw = "./Sprites/Walls/Pond/wall_nw.xpm";
	ref->wall_corner_se = "./Sprites/Walls/Pond/wall_se.xpm";
	ref->wall_corner_sw = "./Sprites/Walls/Pond/wall_sw.xpm";
	ref->tile = init_anim(4, "./Sprites/Floor_Tiles/");
	ref->obj = init_anim(4, "./Sprites/Objects/Flowers/");
	ref->exit = init_anim(2, "./Sprites/Exit/Typhoon/");
	ref->pj_idle = init_anim(5, "./Sprites/Characters/Frog/Idle/");
	return (ref);
}

t_anim	*init_anim(int len, char *path)
{
	t_anim	*anim;
	t_anim	*iterator;
	t_anim	*previous;
	char	*file;
	int		i;

	i = 0;
	file = ft_strdup("0.xpm");
	anim = lstnew_anim(ft_strjoin(path, file));
	i++;
	iterator = anim;
	previous = iterator;
	while (i < len)
	{
		file = ft_substr(file, 1, ft_strlen(file) - 1);
		file = ft_strjoin(ft_itoa(i), file);
		iterator->next = lstnew_anim(ft_strjoin(path, file));
		iterator = iterator->next;
		iterator->prev = previous;
		previous = previous->next;
		i++;
	}
	previous->next = anim;
	anim->prev = previous;
	return (anim);
}
