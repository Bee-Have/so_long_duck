/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:32:29 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/13 14:46:18 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	test(t_mlx_vars *mlx)
{
	(void)mlx;
	printf("TEST\n");
	return (1);
}

void	mlx_print_window(t_mlx_vars *mlx)
{
	int		img_width;
	int		img_height;

	mlx_hook(mlx->mlx_win, 17, 1L<<17, close_window, mlx);
	mlx_hook(mlx->mlx_win, 2, 1, key_hook, mlx);
	mlx_loop_hook(mlx->mlx, print_map, mlx);
	mlx_loop(mlx->mlx);
	// free(mlx->map);
	// free(mlx);
}

int	print_map(t_mlx_vars *mlx)
{
	int		row;
	int		col;
	int		tot_x;
	int		tot_y;
	int		x;

	row = 0;
	// ft_print_tab(mlx->map->map);
	printf("test-[%d]\n", mlx->height);
	tot_y = calc_offset(mlx->map->pxl_img, ft_tablen((const char **)mlx->map->map), mlx->height);
	while (mlx->map->map[row] != NULL)
	{
		col = 0;
		tot_x = calc_offset(mlx->map->pxl_img, ft_strlen(mlx->map->map[0]), mlx->width);
		while (mlx->map->map[row][col] != '\0')
		{
			tot_x += mlx->map->pxl_img;
			sprite_to_img(mlx, mlx->textures->floor, tot_x, tot_y);
			sprite_to_img(mlx, get_right_xpm(mlx, row, col), tot_x, tot_y);
			// mlx->tmp_img = mlx_xpm_file_to_image(mlx->mlx, mlx->textures->floor, &x, &x);
			// mlx->tmp_addr = mlx_get_data_addr(mlx->tmp_img, &mlx->bits_pix,
			// 	&mlx->line_length, &mlx->endian);
			// mlx->addr[tot_x + tot_y] = mlx->tmp_addr;
			// mlx->tmp_img = mlx_xpm_file_to_image(mlx->mlx, get_right_xpm(mlx, row, col), &x, &x);
			// mlx->tmp_addr = mlx_get_data_addr(mlx->tmp_img, &mlx->bits_pix,
			// 	&mlx->line_length, &mlx->endian);
			// mlx->addr[tot_x + tot_y] = mlx->tmp_addr;
			col++;
		}
		tot_y += mlx->map->pxl_img;
		row++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, tot_x, tot_y);
	return (1);
}

void	sprite_to_img(t_mlx_vars *mlx, char *path, int tot_x, int tot_y)
{
	void	*tmp_img;
	char	*tmp_addr;
	int		x;
	int		i;

	i = 0;
	tmp_img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	tmp_img = mlx_xpm_file_to_image(mlx->mlx, path, &x, &x);
	tmp_addr = mlx_get_data_addr(tmp_img, &mlx->bits_pix,
				&mlx->line_length, &mlx->endian);
	while (tmp_addr[i] != '\0')
	{
		mlx->addr[i + (tot_x + tot_y)] = tmp_addr[i];
		i++;
	}
	// mlx->addr[tot_x + tot_y] = tmp_addr;
	mlx_destroy_image(mlx->mlx, tmp_img);
}
