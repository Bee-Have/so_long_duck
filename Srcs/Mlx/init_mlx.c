/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:17:06 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/05 14:50:02 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_mlx_vars	*init_window(void)
{
	t_mlx_vars	*my_mlx;

	my_mlx = init_mlx_struct();
	my_mlx->mlx_win = mlx_new_window(my_mlx->mlx, my_mlx->width
			, my_mlx->height, "so_long");
	my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->width, my_mlx->height);
	my_mlx->addr = mlx_get_data_addr(my_mlx->img, &my_mlx->bits_pix,
			&my_mlx->line_length, &my_mlx->endian);
	return (my_mlx);
}