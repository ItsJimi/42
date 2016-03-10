/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:40:53 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/10 16:22:11 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	drawy(t_mlx *mlx, int wall, int x)
{
	int		y;

	y = (mlx->h / 2) - (wall / 2);
	while (y < (mlx->h / 2) + (wall / 2))
	{
		draw_img_view(mlx, 0xffffff, x, y);
		y++;
	}
}

void		drawx(t_mlx *mlx)
{
	int		x;
	float	length;
	float	wall;

	x = 0;
	length = 0;
	wall = 0;
	while (x < mlx->w)
	{
		length = line(mlx, 0);
		printf("%f\n", length);
		wall = mlx->h / (length * 2);
		drawy(mlx, wall, x);
		x++;
	}
}
