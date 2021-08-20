/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:11:48 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/20 12:36:09 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	anim_name_managment(char **file, int denominator)
{
	char	*sufix;
	char	*prefix;
	
	sufix = ft_substr(*file, 1, ft_strlen(*file) - 1);
	free(*file);
	prefix = ft_itoa(denominator);
	*file = ft_strjoin(prefix, sufix);
	free(prefix);
	free(sufix);
}

t_anim	*lstnew_anim(char *content)
{
	t_anim	*head;

	head = NULL;
	head = (t_anim *)malloc(sizeof(t_anim));
	if (!head)
		return (NULL);
	head->img = ft_strdup(content);
	head->played = 0;
	head->next = NULL;
	head->prev = NULL;
	free(content);
	return (head);
}
