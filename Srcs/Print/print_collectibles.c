/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:37:21 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/20 16:18:25 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	print_collectibles_left(int collectibles)
{
	char	*tmp;
	char	*tmp_col;
	char	*final;

	tmp_col = ft_itoa(collectibles);
	tmp = ft_strjoin("\n", tmp_col);
	final = ft_strjoin(tmp_col, " COLLECTIBLES left \n");
	ft_putstr(final);
	free(tmp);
	free(tmp_col);
	free(final);
}