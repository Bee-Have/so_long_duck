/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:08:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/12 14:39:20 by amarini-         ###   ########.fr       */
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
	my_mlx->img = NULL;
	my_mlx->bits_pix = 0;
	my_mlx->line_length = 0;
	my_mlx->endian = 0;
	my_mlx->width = 100;
	my_mlx->height = 100;

	my_mlx->map = init_map();
	my_mlx->textures = init_textures_paths();
	return (my_mlx);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = NULL;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->pj_pos[0] = -1;
	map->pj_pos[1] = -1;
	map->pxl_img = -1;
	return (map);
}

t_textures	*init_textures_paths(void)
{
	t_textures	*textures;
	
	textures = NULL;
	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures->floor = "./Sprites/Floor_Tiles/water_tile.xpm";
	textures->wall = "./Sprites/Walls/Pond/wall.xpm";
	textures->wall_n = "./Sprites/Walls/Pond/wall_n.xpm";
	textures->wall_s = "./Sprites/Walls/Pond/wall_s.xpm";
	textures->wall_e = "./Sprites/Walls/Pond/wall_e.xpm";
	textures->wall_w = "./Sprites/Walls/Pond/wall_w.xpm";
	textures->wall_corner_ne = "./Sprites/Walls/Pond/wall_ne.xpm";
	textures->wall_corner_nw = "./Sprites/Walls/Pond/wall_nw.xpm";
	textures->wall_corner_se = "./Sprites/Walls/Pond/wall_se.xpm";
	textures->wall_corner_sw = "./Sprites/Walls/Pond/wall_sw.xpm";
	textures->obj = "./Sprites/Objects/flowers.xpm";

	textures->exit = init_anim(2, "./Sprites/Exit/Typhoon/");
	textures->pj_idle = init_anim(5, "./Sprites/Characters/Frog/Idle/");
	textures->pj_walk = init_anim(8, "./Sprites/Characters/Frog/Walk/");
	
	return (textures);
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
