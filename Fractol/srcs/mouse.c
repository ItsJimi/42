/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:28:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/22 21:01:52 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_mlx *mlx)
{
	double	tmp;
	double	scal[2];

	scal[0] = (mlx->x2 - mlx->x1);
	scal[1] = (mlx->y2 - mlx->y1);
	mlx->x = x / (mlx->w / scal[0]) + mlx->x1;
	mlx->y = y / (mlx->h / scal[1]) + mlx->y1;
	tmp = mlx->x1;
	mlx->x1 = mlx->x - (scal[0] * 0.4);
	mlx->x2 = mlx->x + (scal[0] * 0.4);
	tmp = mlx->y1;
	mlx->y1 = mlx->y - (scal[1] * 0.4);
	mlx->y2 = mlx->y + (scal[1] * 0.4);
	mlx->zoom *= 0.8;
}

void	zoom_out(int x, int y, t_mlx *mlx)
{
	double	tmp;
	double	scal[2];

	scal[0] = (mlx->x2 - mlx->x1);
	scal[1] = (mlx->y2 - mlx->y1);
	mlx->x = x / (mlx->w / scal[0]) + mlx->x1;
	mlx->y = y / (mlx->h / scal[1]) + mlx->y1;
	tmp = mlx->x1;
	mlx->x1 = mlx->x - (scal[0] / 1.60);
	mlx->x2 = mlx->x + (scal[0] / 1.60);
	tmp = mlx->y1;
	mlx->y1 = mlx->y - (scal[1] / 1.60);
	mlx->y2 = mlx->y + (scal[1] / 1.60);
	mlx->zoom *= 1.25;
}

int		mouse(int c, int x, int y, t_mlx *mlx)
{
	mlx->img->addr = ft_memset(mlx->img->addr, 0, mlx->w * mlx->h * 4 - 1);
	if (c == 1 || c == 4)
		zoom_in(x, y, mlx);
	else if (c == 2 || c == 5)
		zoom_out(x, y, mlx);
	draw(mlx);
	return (0);
}
