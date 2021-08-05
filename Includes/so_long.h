/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:35:00 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/05 14:49:01 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../Libs/libft_duck/Includes/libft.h"
#include "../Libs/Lib_get_file/Includes/ft_get_file.h"
#include "../Libs/minilibx_opengl_20191021/mlx.h"

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*mlx_win;

	void	*img;
	char	*addr;
	int		bits_pix;
	int		line_length;
	int		endian;
	int		pxl_x;
	int		pxl_y;
	int		width;
	int		height;
}				t_mlx_vars;


typedef struct		s_map_info
{
	char	**map;

	char	*floor;

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
}					t_map_info;

//MAIN
void		main_manager(char **map_good);
int			map_check(char **map);

//MLX
t_mlx_vars	*init_window(void);
void	mlx_print_window(t_map_info *map_info, t_mlx_vars *my_mlx);

//STRUCTS MANAGMENT
t_map_info	*init_map_info(void);
t_mlx_vars	*init_mlx_struct(void);

//ERROR
int			error_message(char *msg);
