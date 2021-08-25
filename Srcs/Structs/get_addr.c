/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:47:30 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/25 17:01:55 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

char	*get_addr(t_mlx_vars *mlx,  char *path)
{
	t_img	*img;
	char	*addr;
	int		size;

	img = init_img();
	img->img = mlx_xpm_file_to_image(mlx->mlx, path, &size, &size);
	addr = mlx_get_data_addr(img->img, &img->bits_pxl, &mlx->img->img_len
		, &img->endian);
	size = mlx->img->img_len * 36;
	black_to_transparency(addr, size);
	mlx_destroy_image(mlx->mlx, img->img);
	free(img);
	return (addr);
}
