/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:43:42 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/19 15:34:30 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_img(t_mlx *mlx, int i, int x, int y)
{
	int		color;

	i *= 20;
	color = (i | (i << mlx->change_color));
	if (((x >= 0) && (y >= 0)) && ((x < mlx->w) && (y < mlx->h)))
	{
		mlx->img->addr[y * mlx->img->size_l + x * mlx->img->bpp / 8] = color
		% 256;
		color /= 256;
		mlx->img->addr[y * mlx->img->size_l + x * mlx->img->bpp / 8 + 1] = color
		% 256;
		color /= 256;
		mlx->img->addr[y * mlx->img->size_l + x * mlx->img->bpp / 8 + 2] = color
		% 256;
		color /= 256;
		mlx->img->addr[y * mlx->img->size_l + x * mlx->img->bpp / 8 + 3] = 0;
		color /= 256;
	}
}

void	draw(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	while (y < mlx->h)
	{
		x = 0;
		while (x < mlx->w)
		{
			if (mlx->av == 1)
				i = mandelbrot(mlx, x, y, 0);
			if (i != mlx->max)
				draw_img(mlx, i, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
