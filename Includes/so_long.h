/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:35:00 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/10 18:51:54 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_get_file.h"
#include "mlx.h"

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*mlx_win;

	void	*img;
	char	*addr;
	int		bits_pix;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	
	int		pj_pos[2];
}				t_mlx_vars;


typedef struct		s_map_info
{
	char	**map;

	char	*floor;

	char	*wall;
	char	*wall_n;
	char	*wall_s;
	char	*wall_e;
	char	*wall_w;
	char	*wall_corner_ne;
	char	*wall_corner_nw;
	char	*wall_corner_se;
	char	*wall_corner_sw;

	char	*exit;
	char	*obj;

	char	*pj;

	int		pxl_img;
}					t_map_info;

//MAIN
void		main_manager(char **map_good);
int			map_open_check(char **map);

//MAP PARSING
int			calc_offset(int pxl, int max_map, int max_win);
char		*get_right_wall(t_map_info *map_info, int row, int col);
int			map_chars_check(char **map, t_mlx_vars *mlx);

//MLX INIT
void		init_window(t_mlx_vars *mlx);
int			mlx_check_size_window(t_map_info *mapinfo, t_mlx_vars *mlx);

//MLX
void		mlx_print_window(t_map_info *map_info, t_mlx_vars *my_mlx);
void		print_map(t_map_info *mapinfo, t_mlx_vars *mlx, char **map);

//MLX EVENTS
int			key_hook(int keycode, t_mlx_vars **mlx);
int			close_window(t_mlx_vars **mlx);

//GAMEPLAY
void		move_pj_map_pos(t_map_info *map_info, int *pos);

//STRUCTS MANAGMENT
t_map_info	*init_map_info(void);
t_mlx_vars	*init_mlx_struct(void);

//ERROR
int			error_message(char *msg);
