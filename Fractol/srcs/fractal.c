/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:59:25 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/22 21:01:51 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_mlx *mlx, int x, int y, int i)
{
	double	z1;
	double	z2;
	double	c1;
	double	c2;
	double	tmp;

	c1 = (double)x / (mlx->w / (mlx->x2 - mlx->x1)) + mlx->x1 + mlx->movex;
	c2 = (double)y / (mlx->h / (mlx->y2 - mlx->y1)) + mlx->y1 + mlx->movey;
	z1 = 0;
	z2 = 0;
	while ((z1 * z1) + (z2 * z2) < 4 && i < mlx->max)
	{
		tmp = z1;
		z1 = (z1 * z1) - (z2 * z2) + c1;
		z2 = 2 * z2 * tmp + c2;
		i++;
	}
	return (i);
}

int		julia(t_mlx *mlx, int x, int y, int i)
{
	double	z1;
	double	z2;
	double	c1;
	double	c2;
	double	tmp;

	c1 = mlx->mousex;
	c2 = mlx->mousey;
	z1 = (double)x / (mlx->w / (mlx->x2 - mlx->x1)) + mlx->x1 + mlx->movex;
	z2 = (double)y / (mlx->h / (mlx->y2 - mlx->y1)) + mlx->y1 + mlx->movey;
	while ((z1 * z1) + (z2 * z2) < 4 && i < mlx->max)
	{
		tmp = z1;
		z1 = (z1 * z1) - (z2 * z2) + c1;
		z2 = 2 * z2 * tmp + c2;
		i++;
	}
	return (i);
}

int		burningship(t_mlx *mlx, int x, int y, int i)
{
	double	z1;
	double	z2;
	double	c1;
	double	c2;
	double	tmp;

	c1 = (double)x / (mlx->w / (mlx->x2 - mlx->x1)) + mlx->x1 + mlx->movex;
	c2 = (double)y / (mlx->h / (mlx->y2 - mlx->y1)) + mlx->y1 + mlx->movey;
	z1 = 0;
	z2 = 0;
	while ((z1 * z1) + (z2 * z2) < 4 && i < mlx->max)
	{
		tmp = z1;
		z1 = (z1 * z1) - (z2 * z2) + c1;
		z2 = 2 * fabs(z2 * tmp) + c2;
		i++;
	}
	return (i);
}

int		douady(t_mlx *mlx, int x, int y, int i)
{
	double	z1;
	double	z2;
	double	c1;
	double	c2;
	double	tmp;

	c1 = -0.132570;
	c2 = -0.766400;
	z1 = (double)x / (mlx->w / (mlx->x2 - mlx->x1)) + mlx->x1 + mlx->movex;
	z2 = (double)y / (mlx->h / (mlx->y2 - mlx->y1)) + mlx->y1 + mlx->movey;
	while ((z1 * z1) + (z2 * z2) < 4 && i < mlx->max)
	{
		tmp = z1;
		z1 = (z1 * z1) - (z2 * z2) + c1;
		z2 = 2 * z2 * tmp + c2;
		i++;
	}
	return (i);
}
