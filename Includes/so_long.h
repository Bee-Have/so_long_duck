/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:35:00 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/04 14:14:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../Libs/libft_duck/Includes/libft.h"
#include "../Libs/Lib_get_file/Includes/ft_get_file.h"
#include "../Libs/minilibx_opengl_20191021/mlx.h"

typedef struct		s_map_info
{
	char	**map;
	char	*floor;
	char	*wall_n;
	char	*wall_s;
	char	*wall_e;
	char	*wall_w;
	char	*wall_corner_nw;
	char	*wall_corner_ne;
	char	*wall_corner_sw;
	char	*wall_corner_se;
}					t_map_info;

//MAIN
void	main_manager(char **map);
int		map_check(char **map);

//ERROR
int		error_message(char *msg);
