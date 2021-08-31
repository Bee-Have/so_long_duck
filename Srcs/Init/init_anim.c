/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:11:48 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/31 15:49:10 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_anim	*init_anim(t_mlx_vars *mlx, int len, char *path)
{
	t_anim	*anim;
	t_anim	*iterator;
	char	*file;
	char	*tmp;
	int		i;

	i = 0;
	file = ft_strdup("0.xpm");
	tmp = ft_strjoin(path, file);
	anim = lstnew_anim(mlx, tmp);
	++i;
	iterator = anim;
	while (i < len)
	{
		anim_name_managment(&file, i);
		tmp = ft_strjoin(path, file);
		iterator->next = lstnew_anim(mlx, tmp);
		iterator = iterator->next;
		i++;
	}
	free(file);
	iterator->next = anim;
	return (anim);
}

void	anim_name_managment(char **file, int denominator)
{
	char	*sufix;
	char	*prefix;
	char	*result;

	sufix = ft_substr(*file, 1, ft_strlen(*file) - 1);
	free(*file);
	prefix = ft_itoa(denominator);
	*file = ft_strjoin(prefix, sufix);
	free(prefix);
	free(sufix);
	return ;
}

t_anim	*lstnew_anim(t_mlx_vars *mlx, char *content)
{
	t_anim	*head;

	head = NULL;
	head = (t_anim *)malloc(sizeof(t_anim));
	if (!head)
		return (NULL);
	head->img = make_img(mlx, content);
	head->played = 0;
	head->next = NULL;
	free(content);
	return (head);
}
