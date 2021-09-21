/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:33:21 by amarini-          #+#    #+#             */
/*   Updated: 2021/09/21 14:41:04 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	check_path(char *str)
{
	int		i;
	
	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[--i] == 'e' && str[--i] == 'b')
		return (0);
	return (-1);
}
