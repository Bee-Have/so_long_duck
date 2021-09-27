/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:35:00 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/27 17:17:38 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include "libft.h"
# include "ft_get_file.h"
# include "mlx.h"

# define NOT_BONUS -2
# define ANIM_PJ 3
# define ANIM_MOB 10
# define ANIM_OBJS 10

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

typedef struct s_anim
{
	t_img			img;
	struct timeval	played;
	struct s_anim	*next;
}				t_anim;

typedef struct s_vec2
{
	int		x;
	int		y;
}				t_vec2;

typedef struct s_objs_parent
{
	int		count;
	char	*path;
	int		sprites;
	t_anim	*anim;
	t_vec2	*pos;
}				t_objs_parent;

typedef struct s_mob
{
	t_vec2			pos;
	t_vec2			dir;
	int				moves;
	int				wait;
	struct s_mob	*next;
}				t_mob;

typedef struct s_player
{
	int				moves;
	int				pj_moved;
	t_vec2			pj_pos;
	t_anim			*pj_idle;
}			t_player;

typedef struct s_gp
{
	t_player		pj;
	int				mobs_count;
	t_anim			*anim_mob;
	t_mob			*mobs;
	t_objs_parent	coll;
	t_objs_parent	exits;
}				t_gp;

typedef struct s_refs
{
	t_img	bad;

	t_img	wall;
	t_img	wall_n;
	t_img	wall_s;
	t_img	wall_e;
	t_img	wall_w;
	t_img	wall_corner_ne;
	t_img	wall_corner_nw;
	t_img	wall_corner_se;
	t_img	wall_corner_sw;

	t_anim	*tile;
}				t_refs;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*mlx_win;

	t_img	img;

	t_gp	gp;
	int		pxl_img;
	char	**map;
	t_refs	ref;
}				t_mlx_vars;

//MAIN
void		main_manager(char **map_good);

//PARSING
int			check_path(char *str);
int			map_open_check(char **map);
int			map_chars_check(char **map);
int			check_wrong_chars(char c);
int			map_check_mobs(char **map);
int			map_rectangle_check(char **map);

//STRUCT INIT
t_gp		init_gameplay(void);
t_img		init_img(void);

//INIT MLX
t_mlx_vars	*init_mlx_struct(void);
void		init_window(t_mlx_vars *mlx);
int			mlx_check_size_window(t_mlx_vars *mlx);

//INIT ANIMS
t_anim		*init_anim(t_mlx_vars *mlx, int len, char *path);
t_anim		*lstnew_anim(t_mlx_vars *mlx, char *content);
void		anim_name_managment(char **file, int denominator);

//INIT SPRITES
t_refs		init_refs_paths(t_mlx_vars *mlx);
void		init_refs_anims(t_mlx_vars *mlx, t_refs *ref);
t_img		make_img(t_mlx_vars *mlx, char *path);
void		black_to_transparency(char *addr, size_t len);

//INIT GAMEPLAY
void		find_player(t_mlx_vars *mlx);
void		add_objs(t_objs_parent *objs, int y, int x);
void		find_mobs(t_mlx_vars *mlx, char **map);
void		find_exits(t_mlx_vars *mlx, char **map);

//MOBS INIT
t_mob		*init_mobs(t_mlx_vars *mlx, char **map, int *pos, int mobs_count);
t_mob		*new_mob(char **map, int *pos);
void		find_direction(char **map, int *pos, t_vec2 *dir, int *max);
void		find_max_x(char **map, int *pos, t_vec2 (*dir), int *max, int col);
void		find_max_y(char **map, int *pos, t_vec2 (*dir), int *max, int row);

//GAMEPLAY PJ
void		move_pj_map_pos(t_mlx_vars *mlx, t_vec2 pos);
void		erase_old_pos(t_mob *mob, char **map);

//GAMEPLAY MOBS
void		move_mob_manager(t_mlx_vars *mlx);
void		move_mob(t_mlx_vars *mlx, t_mob *mob, char **map);
void		change_mob_dir(t_mob *mob);

//AGEMPLAY EXITS/COLLECTIBLES
t_img		get_obj_sprite(t_mlx_vars *mlx, t_objs_parent parent, int y, int x);
void		update_objs(t_mlx_vars *mlx);
void		delete_collectible(t_mlx_vars *mlx, t_vec2 pos);

//PRINTING
void		mlx_print_window(t_mlx_vars *mlx);
int			print_all(t_mlx_vars *mlx);
void		print_map(t_mlx_vars *mlx, int floor);
void		print_sprites(t_mlx_vars *mlx);
void		add_img(t_mlx_vars *mlx, t_img addr, int tot_x, int tot_y);

//MLX PRINT UTILS
int			offset(int pxl, int max_map, int max_win);

//GET IMGS TO PRINT
t_img		get_wall(char **map, t_refs textures, int row, int col);
t_img		get_right_xpm(t_mlx_vars *mlx, int row, int col);
t_img		get_mob(int play_time, int x, int y, t_mob *mobs);
t_img		get_anim(t_anim **anim, int play_time);

//MLX EVENTS
int			key_hook(int keycode, t_mlx_vars *mlx);
int			close_window(t_mlx_vars *mlx);

//FREE
void		free_manager(t_mlx_vars *mlx, int status);
void		free_mobs(t_mlx_vars *mlx);
void		free_sprites(t_mlx_vars *mlx);
void		free_anim(t_mlx_vars *mlx, t_anim **stack, int len);
void		free_img(t_mlx_vars *mlx, t_img *img);

//PRINTS
void		print_manager(t_mlx_vars *mlx);
void		print_manager_console(int moves);
void		print_collectibles(t_mlx_vars *mlx);

//ERROR
int			error_message(char *msg);

#endif