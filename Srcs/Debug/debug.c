/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:47:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/23 11:56:00 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	print_anim(t_anim *stack, int len)
{
	int		i;
	char	*tmp;
	char	*tmp_tmp;

	i = 0;
	while (i < len)
	{
		tmp_tmp = stack->img;
		tmp = ft_strdup(tmp_tmp);
		tmp_tmp = ft_strjoin("[", tmp);
		free(tmp);
		tmp = ft_strjoin(tmp_tmp, "]");
		free(tmp_tmp);
		write(1, tmp, ft_strlen(tmp));
		stack = stack->next;
		free(tmp);
		i++;
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
	return ;
}
