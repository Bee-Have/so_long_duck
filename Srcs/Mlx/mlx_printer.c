/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/05 15:09:48 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	mlx_print_window(t_map_info *map_info, t_mlx_vars *my_mlx)
{
	int		img_width;
	int		img_height;

	printf("SUCCESS !!!!!!!\n");
	printf("IT'S FUCKING WORKING !!!\n");

	my_mlx->img = mlx_xpm_file_to_image(my_mlx->mlx, map_info->floor, &img_width, &img_height);

	mlx_put_image_to_window(my_mlx->mlx, my_mlx->mlx_win, my_mlx->img, 10, 10);
	mlx_put_image_to_window(my_mlx->mlx, my_mlx->mlx_win, my_mlx->img, 0, 0);
	mlx_loop(my_mlx->mlx);
}


