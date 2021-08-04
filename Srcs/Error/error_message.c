/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:25:37 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/04 14:14:32 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	error_message(char *msg)
{
	char	*error;
	char	*full_msg;

	error = ft_strjoin("Error : ", msg);
	full_msg = ft_strjoin(error, "\n");
	ft_putstr(full_msg);
	free(error);
	free(full_msg);
	return (-1);
}
