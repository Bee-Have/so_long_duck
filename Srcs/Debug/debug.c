/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:47:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/25 19:03:05 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

//a revoir (les anims sont des addr d'img xpm donc nope nope)
// void	print_anim(t_anim *stack, int len)
// {
// 	int		i;
// 	char	*tmp;
// 	char	*tmp_tmp;

// 	i = 0;
// 	while (i < len)
// 	{
// 		tmp_tmp = stack->img;
// 		tmp = ft_strdup(tmp_tmp);
// 		tmp_tmp = ft_strjoin("[", tmp);
// 		free(tmp);
// 		tmp = ft_strjoin(tmp_tmp, "]");
// 		free(tmp_tmp);
// 		write(1, tmp, ft_strlen(tmp));
// 		stack = stack->next;
// 		free(tmp);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	write(1, "\n", 1);
// 	return ;
// }

void	print_mobs(t_mob *mobs, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		printf("MOB->pos[%d][%d]\n", mobs->pos[0], mobs->pos[1]);
		mobs = mobs->next;
		i++;
	}
	return ;
}
