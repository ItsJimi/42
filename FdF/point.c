/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:21:42 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/28 16:54:25 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		couleur(double t)
{
	return ((RGB(
	127.5 * (cos(t) + 1),
	127.5 * (sin(t) + 1),
	127.5 * (1 - cos(t)))));
}

static void change_color(t_mlx *mlx, t_point ***p, int x, int y)
{
	if (mlx->change_color == 0)
		p[y][x]->color = rand();
	if (mlx->change_color == 1)
		p[y][x]->color = 0xffffff;
	if (mlx->change_color == 2)
		p[y][x]->color = 0xffff00;
	if (mlx->change_color == 3)
		p[y][x]->color = 0xff00ff;
	if (mlx->change_color == 4)
		p[y][x]->color = 0x00ffff;
	if (mlx->change_color == 5)
		p[y][x]->color = 0x000000;
	if (mlx->change_color == 6)
		p[y][x]->color = 0x333333;
	if (mlx->change_color == 7)
		p[y][x]->color = 0x00ff00;
	if (mlx->change_color == 8)
		p[y][x]->color = 0xff0000;
	if (mlx->change_color == 9)
		p[y][x]->color = 0x0000ff;
}

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
	int		x;
	int		y;

	y = 0;
	while (p[y])
	{
		x = 0;
		while (p[y][x])
		{
			(p[y][x])->px = (mlx->decalx) + (mlx->perspx * y) + ((p[y][x])->x +
				(x * mlx->space)) - ((p[y][x])->z * mlx->dim);
			(p[y][x])->py = (mlx->decaly) + (mlx->perspy * x) + ((p[y][x])->y +
				(y * mlx->space)) - ((p[y][x])->z * mlx->dim);
			if (mlx->change_color == 10)
				p[y][x]->color = couleur((double)p[y][x]->z);
			else
				change_color(mlx, p, x, y);
			x++;
		}
		y++;
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
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->mlx, 0, 0);
	str_data(mlx);
}
