/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:50:24 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/12 15:09:21 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int		map_open_check(char **map)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (map[row] != NULL)
	{
		while (map[row][col] != '\0')
		{
			if ((map[row][col] == '0' || map[row][col] == 'C'
				|| map[row][col] == 'E' || map[row][col] == 'P')
				&& (col == 0 || col == ft_strlen((const char *)map[row])
				|| row == 0 || row == ft_tablen((const char **)map)))
			{
				ft_freetab(map);
				return (error_message("map is not closed"));
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}

int		map_chars_check(char **map, t_mlx_vars *mlx)
{
	char	mandatory[4];
	int		row;
	int		col;

	ft_bzero(mandatory, 4);
	row = 0;
	col = 0;
	while (map[row] != NULL)
	{
		if (ft_strchr(map[row],'E'))
			mandatory[0] = 'e';
		if (ft_strchr(map[row], 'C'))
			mandatory[1] = 'c';
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'P')
			{
				mandatory[2] = 'p';
				mlx->map->pj_pos[0] = row;
				mlx->map->pj_pos[1] = col;
			}
			col++;
		}
		col = 0;
		row++;
	}
	if (ft_strncmp(mandatory, "ecp", 4) != 0)
		return (error_message("map does not contain : 'E', 'C' or 'P'"));
	return (0);
}
