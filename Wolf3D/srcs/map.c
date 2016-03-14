/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:38:30 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/14 19:16:48 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map1(t_mlx *mlx, int x, int y)
{
	int		i;
	int		j;

	i = 4;
	j = 0;
	while (j < i)
	{
		if (mlx->p[y][x]->z == 1)
			draw_img_map(mlx, 0xffffff, x + j, y + j);
		else if (x == (int)mlx->beginx && y == (int)mlx->beginy)
			draw_img_map(mlx, 0x00ff00, x + j, y + j);
		else
			draw_img_map(mlx, 0x000000, x + j, y + j);
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
