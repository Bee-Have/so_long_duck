/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:56:56 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/15 12:25:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	print_moves(int moves)
{
	char	*tmp;
	char	*final;

	tmp = ft_itoa(moves);
	final = ft_strjoin(tmp, "\r");
	ft_putstr(final);
	free(tmp);
	free(final);
}
