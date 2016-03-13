/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:38:30 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/13 21:15:41 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map(t_mlx *mlx)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 10;
	while (mlx->p[y])
	{
		x = 0;
		while (mlx->p[y][x])
		{
			if (mlx->p[y][x]->z == 1)
				draw_img_map(mlx, 0xffffff, x * i, y * i);
			else if (x == (int)mlx->beginx && y == (int)mlx->beginy)
				draw_img_map(mlx, 0x00ff00, x * i, y * i);
			else
				draw_img_map(mlx, 0x000000, x * i, y * i);
			x++;
		}
		y++;
	}
}
