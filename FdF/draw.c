/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:28:52 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/25 19:01:16 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	first(t_mlx *mlx, t_line *line, int xincr, int yincr)
{
	int		e;
	int		dxy[2];
	int		i;
	int		xy1[2];

	xy1[0] = line->x1;
	xy1[1] = line->y1;
	dxy[0] = ft_abs((line->x2) - (line->x1));
	dxy[1] = ft_abs((line->y2) - (line->y1));
	e = dxy[0] / 2;
	i = 0;
	while (i < dxy[0])
	{
		xy1[0] += xincr;
		e += dxy[1];
		if (e > dxy[0])
		{
			e -= dxy[0];
			xy1[1] += yincr;
		}
		mlx_pixel_put(mlx->mlx, mlx->win, xy1[0], xy1[1], 0xFFFFFF);
		i++;
	}
}

static void	second(t_mlx *mlx, t_line *line, int xincr, int yincr)
{
	int		e;
	int		dxy[2];
	int		i;
	int		xy1[2];

	xy1[0] = line->x1;
	xy1[1] = line->y1;
	dxy[0] = ft_abs((line->x2) - (line->x1));
	dxy[1] = ft_abs((line->y2) - (line->y1));
	e = dxy[1] / 2;
	i = 0;
	while (i < dxy[1])
	{
		xy1[1] += yincr;
		e += dxy[0];
		if (e > dxy[1])
		{
			e -= dxy[1];
			xy1[0] += xincr;
		}
		mlx_pixel_put(mlx->mlx, mlx->win, xy1[0], xy1[1], 0xFFFFFF);
		i++;
	}
}

static void	draw_line(t_mlx *mlx, t_line *line)
{
	int		xincr;
	int		yincr;

	if ((line->x1) < (line->x2))
		xincr = 1;
	else
		xincr = -1;
	if ((line->y1) < (line->y2))
		yincr = 1;
	else
		yincr = -1;
	if (ft_abs((line->x2) - (line->x1)) > ft_abs((line->y2) - (line->y1)))
		first(mlx, line, xincr, yincr);
	else
		second(mlx, line, xincr, yincr);
}

int			draw2(t_mlx *mlx, t_line *line, t_point ***point)
{
	int		x;
	int		y;

	y = 0;
	while (y < mlx->sizey - 1)
	{
		x = 0;
		while (x < mlx->sizex)
		{
			line->x1 = point[y][x]->x - point[y][x]->z * AAA;
			line->y1 = point[y][x]->y - point[y][x]->z * AAA;
			line->x2 = point[y + 1][x]->x - point[y + 1][x]->z * AAA;
			line->y2 = point[y + 1][x]->y - point[y + 1][x]->z * AAA;
			draw_line(mlx, line);
			x++;
		}
		y++;
	}
	return (0);
}

int			draw(t_mlx *mlx, t_line *line, t_point ***point)
{
	int		x;
	int		y;

	y = 0;
	while (y < mlx->sizey)
	{
		x = 0;
		while (x < mlx->sizex - 1)
		{
			line->x1 = point[y][x]->x - point[y][x]->z * AAA;
			line->y1 = point[y][x]->y - point[y][x]->z * AAA;
			line->x2 = point[y][x + 1]->x - point[y][x + 1]->z * AAA;
			line->y2 = point[y][x + 1]->y - point[y][x + 1]->z * AAA;
			draw_line(mlx, line);
			x++;
		}
		y++;
	}
	return (0);
}
