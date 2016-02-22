/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:36:37 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/22 21:01:54 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

void			draw_tree(t_mlx *mlx, t_line *line)
{
	int		x2;
	int		y2;

	if (line->y2 != 0)
	{
		x2 = mlx->x + line->x1 + (int)(cos(to_rad(line->x2)) * line->y2 *
			10.0);
		y2 = mlx->y + line->y1 + (int)(sin(to_rad(line->x2)) * line->y2 *
			10.0);
		draw_line(mlx, new_line(line->x1, line->y1, x2, y2), 0xffffff);
		draw_tree(mlx, new_line(x2, y2, line->x2 - (int)-mlx->mousex,
			line->y2 - 1));
		draw_tree(mlx, new_line(x2, y2, line->x2 + (int)-mlx->mousex,
			line->y2 - 1));
	}
	free(line);
}

static void		first(t_mlx *mlx, t_line *line, int xincr, int yincr)
{
	int		e;
	int		dx;
	int		dy;
	int		i;

	dx = ft_abs((line->x2) - (line->x1));
	dy = ft_abs((line->y2) - (line->y1));
	e = dx / 2;
	i = 0;
	while (i < dx)
	{
		(line->x1) += xincr;
		e += dy;
		if (e > dx)
		{
			e -= dx;
			(line->y1) += yincr;
		}
		draw_img(mlx, line->color, line->x1, line->y1);
		i++;
	}
}

static void		second(t_mlx *mlx, t_line *line, int xincr, int yincr)
{
	int		e;
	int		dx;
	int		dy;
	int		i;

	dx = ft_abs((line->x2) - (line->x1));
	dy = ft_abs((line->y2) - (line->y1));
	e = dy / 2;
	i = 0;
	while (i < dy)
	{
		(line->y1) += yincr;
		e += dx;
		if (e > dy)
		{
			e -= dy;
			(line->x1) += xincr;
		}
		draw_img(mlx, line->color, line->x1, line->y1);
		i++;
	}
}

int				draw_line(t_mlx *mlx, t_line *line, int color)
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
	line->color = color;
	if (ft_abs((line->x2) - (line->x1)) > ft_abs((line->y2) - (line->y1)))
		first(mlx, line, xincr, yincr);
	else
		second(mlx, line, xincr, yincr);
	free(line);
	return (1);
}
