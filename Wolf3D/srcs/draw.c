/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:35:48 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/04 16:57:02 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_img(t_mlx *mlx, int color, int x, int y)
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

void	drawy(t_mlx *mlx, int wall, int x)
{
	int		y;

	y = (mlx->h / 2) - (wall / 2);
	while (y < (mlx->h / 2) + (wall / 2))
	{
		draw_img(mlx, 0xffffff, x, y);
		y++;
	}
}

void	drawx(t_mlx *mlx, t_point ***p)
{
	int		x;
	int		dist;
	int		wall;

	x = 0;
	dist = 0;
	wall = 0;
	while (x < mlx->w)
	{
		dist = dep(mlx, p);
		wall = mlx->h / dist;
		drawy(mlx, wall, x);
		x++;
	}
}

void	draw(t_mlx *mlx, t_point ***p)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	// while (p[y])
	// {
	// 	x = 0;
	// 	while (p[y][x])
	// 	{
	// 		if (p[y][x]->z == 1)
	// 			draw_img(mlx, 0xffffff, x, y);
	// 		else
	// 			draw_img(mlx, 0x000000, x, y);
	// 		x++;
	// 	}
	// 	y++;
	// }
	drawx(mlx, p);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	str_data(mlx);
}
