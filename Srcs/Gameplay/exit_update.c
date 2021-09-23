/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:06:26 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/23 12:47:51 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_exits(t_mlx_vars *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->gp.e_count)
	{
		//this is no longer valid since the type of the variable ahs changed
		// if (mlx->map[mlx->map->exit_pos[i][0]]
			// [mlx->map->exit_pos[i][1]] == '0')
			// mlx->map[mlx->map->exit_pos[i][0]]
			// [mlx->map->exit_pos[i][1]] = 'E';
		++i;
	}
	return ;
}
