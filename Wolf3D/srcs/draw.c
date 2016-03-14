/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:35:48 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/14 19:14:52 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_img_view(t_mlx *mlx, int color, int x, int y)
{
	if (((x >= 0) && (y >= 0)) && ((x < mlx->w) && (y < mlx->h)))
	{
		mlx->imgview->addr[y * mlx->imgview->size_l + x * mlx->imgview->bpp /
		8] = color % 256;
		color /= 256;
		mlx->imgview->addr[y * mlx->imgview->size_l + x * mlx->imgview->bpp / 8
		+ 1] = color % 256;
		color /= 256;
		mlx->imgview->addr[y * mlx->imgview->size_l + x * mlx->imgview->bpp / 8
		+ 2] = color % 256;
		color /= 256;
		mlx->imgview->addr[y * mlx->imgview->size_l + x * mlx->imgview->bpp / 8
		+ 3] = 0;
		color /= 256;
	}
}

void	draw_img_map(t_mlx *mlx, int color, int x, int y)
{
	if (((x >= 0) && (y >= 0)) && ((x < mlx->w) && (y < mlx->h)))
	{
		mlx->imgmap->addr[y * mlx->imgmap->size_l + x * mlx->imgmap->bpp / 8] =
		color % 256;
		color /= 256;
		mlx->imgmap->addr[y * mlx->imgmap->size_l + x * mlx->imgmap->bpp / 8 +
		1] = color % 256;
		color /= 256;
		mlx->imgmap->addr[y * mlx->imgmap->size_l + x * mlx->imgmap->bpp / 8 +
		2] = color % 256;
		color /= 256;
		mlx->imgmap->addr[y * mlx->imgmap->size_l + x * mlx->imgmap->bpp / 8 +
		3] = 0;
		color /= 256;
	}
}

void	draw(t_mlx *mlx)
{
	drawx(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgview->img, 0, 0);
	if (mlx->map == 1)
	{
		map(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgmap->img, 0, 0);
	}
	str_data(mlx);
}
