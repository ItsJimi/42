/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:38:30 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/15 12:42:34 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map1(t_mlx *mlx, int x, int y)
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

void	map(t_mlx *mlx)
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
