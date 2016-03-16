/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:40:53 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/16 11:45:54 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	drawy(t_mlx *mlx, int wall, int x)
{
	int		y;

	y = (mlx->h / 2) - (wall / 2);
	while (y <= (mlx->h / 2) + (wall / 2))
	{
		draw_img_view(mlx, get_color(mlx, x, y), x, y);
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
	while (x <= mlx->w)
	{
		length = line(mlx, 0, deg);
		printf("%f\n", length);
		wall = mlx->h / length;
		drawy(mlx, wall, x);
		deg += (60 / (float)mlx->w);
		printf("----\n%f\n----\n", deg);
		x++;
	}
}
