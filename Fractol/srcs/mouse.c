/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:28:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/18 17:26:21 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_in(double xspan, double yspan, t_mlx *mlx)
{
	double tmp;

	tmp = mlx->x1;
	mlx->x1 = (mlx->x + (mlx->x2 + mlx->x1) / 2) / 2 - (xspan * 0.4);
	mlx->x2 = (mlx->x + (mlx->x2 + tmp) / 2) / 2 + (xspan * 0.4);
	tmp = mlx->y1;
	mlx->y1 = (mlx->y + (mlx->y2 + mlx->y1) / 2) / 2 - (yspan * 0.4);
	mlx->y2 = (mlx->y + (mlx->y2 + tmp) / 2) / 2 + (yspan * 0.4);
}

static void	zoom_out(double xspan, double yspan, t_mlx *mlx)
{
	mlx->x1 = mlx->x1 - (xspan * 0.52);
	mlx->x2 = mlx->x2 + (xspan * 0.52);
	mlx->y1 = mlx->y1 - (yspan * 0.52);
	mlx->y2 = mlx->y2 + (yspan * 0.52);
}

int			mouse(int c, int x, int y, t_mlx *mlx)
{
	int		xspan;
	int		yspan;

	mlx->img->addr = ft_memset(mlx->img->addr, 0, mlx->w * mlx->h * 4 - 1);
	xspan = mlx->x2 - mlx->x1;
	yspan = mlx->y2 - mlx->y1;
	mlx->x = x / (mlx->w / (mlx->x2 - mlx->x1)) + mlx->x1;
	mlx->y = y / (mlx->h / (mlx->y2 - mlx->y1)) + mlx->y1;
	if (c == 1)
		zoom_in(xspan, yspan, mlx);
	else if (c == 2)
		zoom_out(xspan, yspan, mlx);
	draw(mlx);
	return (0);
}
