/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:38:30 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/20 13:09:54 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		tp(t_mlx *mlx)
{
	if (mlx->p[(int)mlx->beginy][(int)mlx->beginx]->z == 2)
	{
		mlx->p = parse("maps/level1", mlx);
		mlx_destroy_image(mlx->mlx, mlx->imgmap->img);
		free(mlx->imgmap);
		mlx->imgmap = new_img(mlx, mlx->mapw * 10, mlx->maph * 10);
		draw(mlx);
	}
	else if (mlx->p[(int)mlx->beginy][(int)mlx->beginx]->z == 3)
	{
		mlx->p = parse("maps/level2", mlx);
		mlx_destroy_image(mlx->mlx, mlx->imgmap->img);
		free(mlx->imgmap);
		mlx->imgmap = new_img(mlx, mlx->mapw * 10, mlx->maph * 10);
		draw(mlx);
	}
	else if (mlx->p[(int)mlx->beginy][(int)mlx->beginx]->z == 4)
	{
		mlx->p = parse("maps/level3", mlx);
		mlx_destroy_image(mlx->mlx, mlx->imgmap->img);
		free(mlx->imgmap);
		mlx->imgmap = new_img(mlx, mlx->mapw * 10, mlx->maph * 10);
		draw(mlx);
	}
}

static void	map1(t_mlx *mlx, int x, int y)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 10;
	while (j < k)
	{
		i = 0;
		while (i < k)
		{
			if (mlx->p[y][x]->z == 1)
				draw_img_map(mlx, 0xffffff, k * x + i, k * y + j);
			else if (x == (int)mlx->beginx && y == (int)mlx->beginy)
				draw_img_map(mlx, 0x00ff00, k * x + i, k * y + j);
			else
				draw_img_map(mlx, 0x000000, k * x + i, k * y + j);
			i++;
		}
		j++;
	}
}

void		map(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (mlx->p[y])
	{
		x = 0;
		while (mlx->p[y][x])
		{
			map1(mlx, x, y);
			x++;
		}
		y++;
	}
}
