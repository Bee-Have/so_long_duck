/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:17:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/06 15:11:42 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	calc_offset(int pxl, int max_map, int max_win, int window)
{
	int		offset;
	int		midd_win;
	int		midd_pxl;

	midd_win = max_win / 2;
	midd_pxl = (pxl * max_map) / 2;
	offset = (midd_pxl * window) / midd_win;
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
	else if (col == 0 && row > 0 && row < ft_tablen((const char **)map_info->map[row]) - 1)
		return (map_info->wall_w);
	else if (col == ft_strlen(map_info->map[row]) - 1 && row > 0
		&& row < ft_tablen((const char **)map_info->map) - 1)
		return (map_info->wall_e);
	return (map_info->wall);
}
