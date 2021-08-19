/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   End.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:28:25 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/19 15:37:14 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	free_manager(t_mlx_vars *mlx)
{
	free(mlx->img);
	ft_freetab(mlx->map->map);
	free(mlx->map);
	free_anim(&mlx->ref->tile);
	free_anim(&mlx->ref->obj);
	free_anim(&mlx->ref->exit);
	free_anim(&mlx->ref->pj_idle);
	free(mlx->ref);
	free(mlx);
	return ;
}

void	free_anim(t_anim **stack)
{
	t_anim	*iterator;

	iterator->prev->prev->next = NULL;
	free(iterator->prev);
	while (*stack)
	{
		iterator = *stack;
		*stack = (*stack)->next;
		free(iterator);
		iterator = NULL;
	}
	free(*stack);
}
