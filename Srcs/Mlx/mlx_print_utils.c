/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:17:07 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/22 12:53:19 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	offset(int pxl, int map_len, int max_win)
{
	int		offset;
	int		max_pxl_win;
	int		midd_pxl;

	midd_pxl = (pxl * map_len) / 2;
	max_pxl_win = pxl * map_len;
	offset = (max_win - max_pxl_win) / 2;
	return (offset);
}

void	black_to_transparency(char *addr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < 3)
		{
			if (addr[i + j] == 0)
				++j;
			else
				break ;
		}
		if (j == 3)
			addr[i] = -1;
		i += 4;
	}
}
