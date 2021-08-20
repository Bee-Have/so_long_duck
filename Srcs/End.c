/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   End.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:28:25 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/20 14:42:57 by amarini-         ###   ########.fr       */
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
	t_anim	*it;

	it = (*stack)->prev;
	it->prev->next = NULL;
	free(it->img);
	free(it);
	while ((*stack)->next)
	{
		it = *stack;
		*stack = (*stack)->next;
		free(it->img);
		free(it);
		it = NULL;
	}
	free((*stack)->img);
	free(*stack);
}
