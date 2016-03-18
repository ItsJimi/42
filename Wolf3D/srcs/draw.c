/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:35:48 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/18 12:03:47 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_color(t_mlx *mlx, float x, float y)
{
	if (mlx->p[(int)y + 1] && (int)y > 0 && mlx->p[(int)y][(int)x - 1] &&
	mlx->p[(int)y][(int)x - 1]->z != 1 && y - (int)y < 0.001)
		return (0xc8a859);
	else if (mlx->p[(int)y - 1] && (int)y > 0 && mlx->p[(int)y][(int)x + 1] &&
	mlx->p[(int)y][(int)x + 1]->z != 1 && x - (int)x < 0.001)
		return (0x96dcb4);
	else if (mlx->p[(int)y + 1] && (int)y > 0 && mlx->p[(int)y][(int)x - 1] &&
	mlx->p[(int)y - 1][(int)x]->z != 1 && x - (int)x < 0.001)
		return (0xdf9fa4);
	else if (mlx->p[(int)y - 1] && (int)y > 0 && mlx->p[(int)y][(int)x + 1] &&
	mlx->p[(int)y + 1][(int)x]->z != 1 && y - (int)y < 0.001)
		return (0x90aada);
	else
		return (0xffffff);
}

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
