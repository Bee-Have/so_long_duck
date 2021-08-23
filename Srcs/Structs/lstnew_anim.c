/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:11:48 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/23 12:35:07 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

char	*anim_name_managment(char *file, int denominator)
{
	char	*sufix;
	char	*prefix;
	char	*result;
	
	sufix = ft_substr(file, 1, ft_strlen(file) - 1);
	free(file);
	prefix = ft_itoa(denominator);
	result = ft_strjoin(prefix, sufix);
	free(prefix);
	free(sufix);
	return (result);
}

t_anim	*lstnew_anim(char *content)
{
	t_anim	*head;

	head = NULL;
	head = (t_anim *)malloc(sizeof(t_anim));
	if (!head)
		return (NULL);
	// head->img = ft_strdup(content);
	head->img = content;
	// free(content);
	head->played = 0;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}
