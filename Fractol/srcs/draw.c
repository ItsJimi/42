/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:43:42 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/22 21:01:51 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_fract(t_mlx *mlx, int i)
{
	int	color;

	i *= 20;
	if (mlx->change_color == 0)
		color = (i | (i << 8) | i << 16);
	else if (mlx->change_color == 1)
		color = (i << 8);
	else if (mlx->change_color == 2)
		color = (i << 16);
	else if (mlx->change_color == 3)
		color = (i | i << 8);
	else if (mlx->change_color == 4)
		color = (i | i << 16);
	else if (mlx->change_color == 5)
		color = (i | (i >> 8) | i >> 16);
	else if (mlx->change_color == 6)
		color = (i >> rand());
	else if (mlx->change_color == 7)
		color = (5648648 * i);
	else
		color = (i | (i << 8) | i << 16);
	return (color);
}

void	draw_img(t_mlx *mlx, int i, int x, int y)
{
	int		color;

	color = color_fract(mlx, i);
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

int		fractal(t_mlx *mlx, int x, int y)
{
	int		i;

	i = 0;
	if (mlx->av == 1)
		i = mandelbrot(mlx, x, y, 0);
	else if (mlx->av == 2)
		i = julia(mlx, x, y, 0);
	else if (mlx->av == 3)
		i = burningship(mlx, x, y, 0);
	else if (mlx->av == 4)
		i = douady(mlx, x, y, 0);
	return (i);
}

void	draw(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	if (mlx->av == 6)
		draw_tree(mlx, new_line(mlx->w / 2, mlx->h, -90, mlx->max));
	else
	{
		while (y < mlx->h)
		{
			x = 0;
			while (x < mlx->w)
			{
				i = fractal(mlx, x, y);
				if (i != mlx->max)
					draw_img(mlx, i, x, y);
				x++;
			}
			y++;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	str_data(mlx);
}
