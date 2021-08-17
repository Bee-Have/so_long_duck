/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:35:00 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/17 18:17:01 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_get_file.h"
#include "mlx.h"

typedef struct	s_map
{
	char	**map;
	int		pj_moved;
	int		pj_pos[2];
	int		pxl_img;
}				t_map;

typedef struct	s_anim
{
	struct s_anim	*prev;
	char			*img;
	int				played;
	struct s_anim	*next;
}				t_anim;

typedef struct	s_textures
{
	char			*wall;
	char			*wall_n;
	char			*wall_s;
	char			*wall_e;
	char			*wall_w;
	char			*wall_corner_ne;
	char			*wall_corner_nw;
	char			*wall_corner_se;
	char			*wall_corner_sw;

	struct s_anim	*floor;
	struct s_anim	*obj;
	struct s_anim	*exit;
	struct s_anim	*pj_idle;
	struct s_anim	*pj_walk;
}				t_textures;

typedef struct	s_mlx_vars
{
	void				*mlx;
	void				*mlx_win;

	struct s_img		*img;

	struct s_map		*map;
	struct s_textures	*textures;
}				t_mlx_vars;

typedef struct	s_img
{
	void				*img;
	char				*addr;
	int					bits_pxl;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}				t_img;

//MAIN
void		main_manager(char **map_good);
int			map_open_check(char **map);

//MLX PRINT UTILS
int			calc_offset(int pxl, int max_map, int max_win);
char		*get_wall(char **map, t_textures *textures, int row, int col);
int			map_chars_check(char **map, t_mlx_vars *mlx);

//TEXTURES
char		*get_right_xpm(t_mlx_vars *mlx, int row, int col);
void		black_to_transparency(char *addr, size_t len);

//MLX INIT
char		*get_animation(t_anim **anim, int play_time);
void		init_window(t_mlx_vars *mlx);
int			mlx_check_size_window(t_mlx_vars *mlx);

//STRUCT INIT
t_map		*init_map(void);
t_textures	*init_textures_paths(void);
t_anim		*init_anim(int len, char *path);
t_img		*init_img(void);

//MLX
void		mlx_print_window(t_mlx_vars *mlx);
int			print_all(t_mlx_vars *mlx);
void		print_map(t_mlx_vars *mlx, int floor);
void		print_sprites(t_mlx_vars *mlx);
void		sprite_to_img(t_mlx_vars *mlx, char *path, int tot_x, int tot_y);

//MLX EVENTS
int			key_hook(int keycode, t_mlx_vars *mlx);
int			close_window(t_mlx_vars *mlx);

//GAMEPLAY
void		move_pj_map_pos(t_mlx_vars *mlx, int *pos);

//STRUCTS MANAGMENT
t_mlx_vars	*init_mlx_struct(void);
t_anim		*lstnew_anim(char *content);

//ERROR
int			error_message(char *msg);

#endif