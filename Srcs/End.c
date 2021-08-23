/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   End.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:28:25 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/23 11:55:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	free_manager(t_mlx_vars *mlx)
{
	free(mlx->img);
	ft_freetab(mlx->map->map);
	free(mlx->map);
	free_anim(&mlx->ref->tile, 4);
	free_anim(&mlx->ref->obj, 4);
	free_anim(&mlx->ref->exit, 2);
	free_anim(&mlx->ref->pj_idle, 5);
	free(mlx->ref);
	free(mlx);
	exit(1);
	return ;
}

void	free_anim(t_anim **stack, int len)
{
	t_anim	*it;
	int		i;

	i = 0;
	while (i < len)
	{
		it = *stack;
		*stack = (*stack)->next;
		// printf("img-[%s]\n", it->img);
		free(it->img);
		free(it);
		i++;
	}
}
