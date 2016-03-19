/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:40:53 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/19 16:13:10 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_sky(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < mlx->h / 2)
	{
		x = 0;
		while (x < mlx->w)
		{
			draw_img_view(mlx, 0xd8eaf5, x, y);
			x++;
		}
		y++;
	}
}

static void	draw_floor(t_mlx *mlx)
{
	int		x;
	int		y;

	y = mlx->h / 2;
	while (y < mlx->h)
	{
		x = 0;
		while (x < mlx->w)
		{
			draw_img_view(mlx, 0x3d2610, x, y);
			x++;
		}
		y++;
	}
}

static void	drawy(t_mlx *mlx, int wall, int x)
{
	int		y;
	int		color;

	y = (mlx->h / 2) - (wall / 2);
	while (y <= (mlx->h / 2) + (wall / 2))
	{
		color = mlx->color;
		draw_img_view(mlx, color, x, y);
		y++;
	}
}

void		drawx(t_mlx *mlx)
{
	int		x;
	float	length;
	float	wall;
	float	deg;

	x = 0;
	length = 0;
	wall = 0;
	deg = mlx->deg - 30;
	draw_sky(mlx);
	draw_floor(mlx);
	while (x <= mlx->w)
	{
		length = line(mlx, 0, deg);
		wall = mlx->h / length;
		drawy(mlx, wall, x);
		deg += (60 / (float)mlx->w);
		x++;
	}
}
