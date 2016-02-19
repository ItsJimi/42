/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:43:42 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/18 14:13:52 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_img(t_mlx *mlx, int color, int x, int y)
{
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
	double	z1;
	double	z2;
	double	c1;
	double	c2;
	int		i;
	int		x;
	int		y;
	double	tmp;

	y = 0;
	while (y < mlx->h)
	{
		x = 0;
		while (x < mlx->w)
		{
			c1 = (double)x / mlx->zoom + mlx->x1;
			c2 = (double)y / mlx->zoom + mlx->y1;
			z1 = 0;
			z2 = 0;
			i = 0;
			while ((z1 * z1) + (z2 * z2) < 4 && i < mlx->max)
			{
				tmp = z1;
				z1 = (z1 * z1) - (z2 * z2) + c1;
				z2 = 2 * z2 * tmp + c2;
				i++;
			}
			if (i == mlx->max)
				draw_img(mlx, 0x3f3fff, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
