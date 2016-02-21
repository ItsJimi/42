/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:36:37 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/21 11:41:49 by jmaiquez         ###   ########.fr       */
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
		x2 = mlx->p->dx + line->x1 + (int)(cos(to_rad(line->x2)) * line->y2 *
			10.0 * mlx->p->zoom);
		y2 = mlx->p->dy + line->y1 + (int)(sin(to_rad(line->x2)) * line->y2 *
			10.0 * mlx->p->zoom);
		d_line(mlx, n_line(line->x1, line->y1, x2, y2),
			color(mlx->p, line->y2 * 20));
		draw_tree(mlx, n_line(x2, y2, line->x2 - (int)-mlx->p->mx % 100,
			line->y2 - 1));
		draw_tree(mlx, n_line(x2, y2, line->x2 + (int)-mlx->p->mx % 100,
			line->y2 - 1));
	}
	free(line);
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
