/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:06:26 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/22 12:53:19 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_exits(t_mlx_vars *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->map->exits)
	{
		if (mlx->map->map[mlx->map->exit_pos[i][0]]
			[mlx->map->exit_pos[i][1]] == '0')
			mlx->map->map[mlx->map->exit_pos[i][0]]
			[mlx->map->exit_pos[i][1]] = 'E';
		++i;
	}
	return ;
}
