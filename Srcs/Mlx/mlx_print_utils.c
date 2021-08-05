/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:17:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/05 18:27:37 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int		calc_window_offset(int pxl, int max_map, int max_win, int window)
{
	int		offset;
	int		midd_win;
	int		midd_pxl;

	midd_win = max_win / 2;
	midd_pxl = (pxl * max_map) / 2;
	offset = (midd_pxl * window) / midd_win;
	return (offset);
}

char	*get_right_wall(char **map)
