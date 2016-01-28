/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:21:42 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/28 13:17:09 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		new_pos_y(t_mlx *mlx, t_point ***p, int x, int y)
{
	mlx->pos[0] = p[y][x]->px;
	mlx->pos[1] = p[y][x]->py;
	if (p[y + 1][x])
	{
		mlx->pos[2] = p[y + 1][x]->px;
		mlx->pos[3] = p[y + 1][x]->py;
	}
	mlx->pos[4] = p[y][x]->color;
}

static void		new_pos_x(t_mlx *mlx, t_point ***p, int x, int y)
{
	mlx->pos[0] = p[y][x]->px;
	mlx->pos[1] = p[y][x]->py;
	if (p[y][x + 1])
	{
		mlx->pos[2] = p[y][x + 1]->px;
		mlx->pos[3] = p[y][x + 1]->py;
	}
	mlx->pos[4] = p[y][x]->color;
}

t_point			***dep_point(t_mlx *mlx, t_point ***p)
{
	int		i;
	int		j;

	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			(p[i][j])->px = (mlx->decalx) + (mlx->perspx * i) + ((p[i][j])->x +
				(j * mlx->space)) - ((p[i][j])->z * mlx->dim);
			(p[i][j])->py = (mlx->decaly) + (mlx->perspy * j) + ((p[i][j])->y +
				(i * mlx->space)) - ((p[i][j])->z * mlx->dim);
			j++;
		}
		i++;
	}
	return (p);
}

void			draw_point(t_mlx *mlx, t_point ***p)
{
	int		x;
	int		y;

	y = 0;
	while (p[y])
	{
		x = 0;
		while (p[y][x])
		{
			if (p[y][x + 1])
			{
				new_pos_x(mlx, p, x, y);
				draw_line(mlx, mlx->pos);
			}
			if (p[y + 1] && p[y + 1][x])
			{
				new_pos_y(mlx, p, x, y);
				draw_line(mlx, mlx->pos);
			}
			x++;
		}
		y++;
	}
	//mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, 425, 0, 0x6f5c87, "===[ F D F ]===");
}
