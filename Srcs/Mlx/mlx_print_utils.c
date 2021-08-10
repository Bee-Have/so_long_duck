/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:17:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/10 17:44:57 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	calc_offset(int pxl, int map_len, int max_win)
{
	int		offset;
	int		max_pxl_win;
	int		midd_pxl;

	midd_pxl = (pxl * map_len) / 2;
	max_pxl_win = pxl * map_len;
	offset = (max_win - max_pxl_win) / 2;
	return (offset);
}

char	*get_right_wall(t_map_info *map_info, int row, int col)
{
	if (col == 0 && row == 0)
		return (map_info->wall_corner_nw);
	else if (col == ft_strlen(map_info->map[row]) - 1 && row == 0)
		return (map_info->wall_corner_ne);
	else if (col > 0 &&  col < ft_strlen(map_info->map[row]) - 1 && row == 0)
		return (map_info->wall_n);
	else if (col == 0 && row == ft_tablen((const char **)map_info->map) - 1)
		return (map_info->wall_corner_sw);
	else if (col == ft_strlen(map_info->map[row]) - 1
		&& row == ft_tablen((const char **)map_info->map) - 1)
		return (map_info->wall_corner_se);
	else if (col > 0 &&  col < ft_strlen(map_info->map[row]) - 1
		&& row == ft_tablen((const char **)map_info->map) - 1 )
		return (map_info->wall_s);
	else if (col == 0 && row > 0 && row < ft_tablen((const char **)map_info->map) - 1)
		return (map_info->wall_w);
	else if (col == ft_strlen(map_info->map[row]) - 1 && row > 0
		&& row < ft_tablen((const char **)map_info->map) - 1)
		return (map_info->wall_e);
	return (map_info->wall);
}
