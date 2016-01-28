/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:36:37 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/28 18:10:46 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_img(t_mlx *mlx, int color, int x, int y)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	color1 = (color & 0xFF00000) >> 24;
	color2 = (color & 0xFF00000) >> 16;
	color3 = (color & 0xFF00000) >> 8;
	mlx->img->addr[y * mlx->img->sizel + x * mlx->img->bpp / 8] = color1;
	mlx->img->addr[y * mlx->img->sizel + x * mlx->img->bpp / 8 + 1] = color2;
	mlx->img->addr[y * mlx->img->sizel + x * mlx->img->bpp / 8 + 2] = color3;
}

static void		first(t_mlx *mlx, int pos[5], int xincr, int yincr)
{
	int		e;
	int		dx;
	int		dy;
	int		i;

	dx = ft_abs((pos[2]) - (pos[0]));
	dy = ft_abs((pos[3]) - (pos[1]));
	e = dx / 2;
	i = 0;
	while (i < dx)
	{
		(pos[0]) += xincr;
		e += dy;
		if (e > dx)
		{
			e -= dx;
			(pos[1]) += yincr;
		}
		draw_img(mlx, pos[4], pos[0], pos[1]);
		i++;
	}
}

static void		second(t_mlx *mlx, int pos[5], int xincr, int yincr)
{
	int		e;
	int		dx;
	int		dy;
	int		i;

	dx = ft_abs((pos[2]) - (pos[0]));
	dy = ft_abs((pos[3]) - (pos[1]));
	e = dy / 2;
	i = 0;
	while (i < dy)
	{
		(pos[1]) += yincr;
		e += dx;
		if (e > dy)
		{
			e -= dy;
			(pos[0]) += xincr;
		}
		draw_img(mlx, pos[4], pos[0], pos[1]);
		i++;
	}
}

int				draw_line(t_mlx *mlx, int pos[5])
{
	int		xincr;
	int		yincr;

	if ((pos[0]) < (pos[2]))
		xincr = 1;
	else
		xincr = -1;
	if ((pos[1]) < (pos[3]))
		yincr = 1;
	else
		yincr = -1;
	if (ft_abs((pos[2]) - (pos[0])) > ft_abs((pos[3]) - (pos[1])))
		first(mlx, pos, xincr, yincr);
	else
		second(mlx, pos, xincr, yincr);
	return (0);
}
