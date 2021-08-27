/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:35:00 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/27 11:51:27 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_get_file.h"
# include "mlx.h"

typedef struct s_mlx_vars
{
	void			*mlx;
	void			*mlx_win;

	struct s_img	*img;

	struct s_map	*map;
	int				mobs_count;
	struct s_mob	*mobs;
	struct ts_refs	*ref;
}				t_mlx_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_pxl;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_map
{
	char	**map;
	int		moves;
	int		pj_moved;
	int		pj_pos[2];
	int		pxl_img;
}				t_map;

typedef struct ts_refs
{
	struct s_img	*wall;
	struct s_img	*wall_n;
	struct s_img	*wall_s;
	struct s_img	*wall_e;
	struct s_img	*wall_w;
	struct s_img	*wall_corner_ne;
	struct s_img	*wall_corner_nw;
	struct s_img	*wall_corner_se;
	struct s_img	*wall_corner_sw;

	struct s_anim	*tile;
	struct s_anim	*obj;
	struct s_anim	*exit;
	struct s_anim	*pj_idle;
}				t_refs;

typedef struct s_mob
{
	int				pos[2];
	int				dir[2];
	int				moves;
	int				wait;
	struct s_anim	*anim;
	struct s_mob	*next;
}				t_mob;

typedef struct s_anim
{
	struct s_anim	*prev;
	struct s_img	*img;
	int				played;
	struct s_anim	*next;
}				t_anim;

//MAIN
void		main_manager(char **map_good);

//PARSING
int			map_open_check(char **map);
int			map_chars_check(char **map, t_mlx_vars *mlx);

//STRUCT INIT
t_map		*init_map(void);
t_img		*init_img(void);

//INIT MLX
t_mlx_vars	*init_mlx_struct(void);
void		init_window(t_mlx_vars *mlx);
int			mlx_check_size_window(t_mlx_vars *mlx);

//INIT ANIMS
t_anim		*init_anim(t_mlx_vars *mlx, int len, char *path);
t_anim		*lstnew_anim(t_mlx_vars *mlx, char *content);
void		anim_name_managment(char **file, int denominator);

//INIT SPRITES
t_refs		*init_refs_paths(t_mlx_vars *mlx);
t_img		*make_img(t_mlx_vars *mlx,  char *path);
void		black_to_transparency(char *addr, size_t len);

//INIT GAMEPLAY
void		find_player(t_mlx_vars *mlx);
void		find_mobs(t_mlx_vars *mlx);

//MOBS INIT
t_mob		*init_mobs(t_mlx_vars *mlx, char **map, int *pos, int mobs_count);
t_mob		*new_mob(t_mlx_vars *mlx, char **map, int *pos);
void		find_direction(char **map, int *pos, int (*dir)[2], int *max);
void		find_max_x(char **map, int *pos, int (*dir)[2], int *max, int col);
void		find_max_y(char **map, int *pos, int (*dir)[2], int *max, int row);

//GAMEPLAY
void		move_pj_map_pos(t_mlx_vars *mlx, int *pos);
t_img		*get_mob(int play_time, int x, int y, t_mob *mobs);
void		move_mob_manager(t_mlx_vars *mlx);

//PRINTING
void		mlx_print_window(t_mlx_vars *mlx);
int			print_all(t_mlx_vars *mlx);
void		print_map(t_mlx_vars *mlx, int floor);
void		print_sprites(t_mlx_vars *mlx);
void		add_img(t_mlx_vars *mlx, t_img *addr, int tot_x, int tot_y);

//MLX PRINT UTILS
int			offset(int pxl, int max_map, int max_win);

//GET IMGS TO PRINT
t_img		*get_wall(char **map, t_refs *textures, int row, int col);
t_img		*get_right_xpm(t_mlx_vars *mlx, int row, int col);
t_img		*get_anim(t_anim **anim, int play_time);

//MLX EVENTS
int			key_hook(int keycode, t_mlx_vars *mlx);
int			close_window(t_mlx_vars *mlx);

//FREE
void		free_manager(t_mlx_vars *mlx);
void		free_mobs(t_mlx_vars *mlx);
void		free_sprites(t_mlx_vars *mlx);
void		free_anim(t_mlx_vars *mlx, t_anim **stack, int len);
void		free_img(t_mlx_vars *mlx, t_img *img);


//ERROR
int			error_message(char *msg);

//DEBUG
void		print_anim(t_anim *stack, int len);
void		print_mobs(t_mob *mobs, int len);

#endif