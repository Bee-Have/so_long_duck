/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:50:24 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/31 12:34:41 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	map_open_check(char **map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row] != NULL)
	{
		while (map[row][col] != '\0')
		{
			if ((map[row][col] == '0' || map[row][col] == 'C'
				|| map[row][col] == 'E' || map[row][col] == 'P'
				|| map[row][col] == 'M')
				&& (col == 0 || col == ft_strlen((const char *)map[row])
				|| row == 0 || row == ft_tablen((const char **)map)))
			{
				ft_freetab(map);
				return (error_message("MAP is not CLOSED"));
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}

int	map_chars_check(char **map)
{
	char	mandatory[4];
	int		row;
	int		col;

	ft_bzero(mandatory, 4);
	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		if (ft_strchr(map[row], 'E'))
			mandatory[0] = 'e';
		if (ft_strchr(map[row], 'C'))
			mandatory[1] = 'c';
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'P')
				mandatory[2] = 'p';
			col++;
		}
		row++;
	}
	if (ft_strncmp(mandatory, "ecp", 4) != 0)
		return (error_message("MAP does not contain : 'E', 'C' or 'P'"));
	return (0);
}

int	map_check_mobs(char **map)
{
	int		row;
	int		col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'M')
				return (error_message(
					"MAP contains ENEMIES but isn't compiled with BONUSES"));
			col++;
		}
		row++;
	}
	return (0);
}
