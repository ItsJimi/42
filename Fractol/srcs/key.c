/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:23:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/20 17:28:39 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear(t_mlx *mlx)
{
	mlx->x1 = -2;
	mlx->x2 = -2 + 4 * mlx->w / mlx->h;
	mlx->y1 = -1.2;
	mlx->y2 = 2;
	mlx->zoom = 200;
	mlx->max = 20;
}

t_mlx	*key_color(int keycode, t_mlx *mlx)
{
	if (keycode == 18)
		mlx->change_color = 0;
	if (keycode == 19)
		mlx->change_color = 1;
	if (keycode == 20)
		mlx->change_color = 2;
	if (keycode == 21)
		mlx->change_color = 3;
	if (keycode == 23)
		mlx->change_color = 4;
	if (keycode == 51)
		clear(mlx);
	if (keycode == 22)
		mlx->change_color = 5;
	if (keycode == 50)
		mlx->change_color = 6;
	return (mlx);
}

t_mlx	*key_yolo(int keycode, t_mlx *mlx)
{
	if (keycode == 123)
		mlx->x1 += 0.01;
	if (keycode == 124)
		mlx->x1 -= 0.01;
	if (keycode == 125)
		mlx->y1 -= 0.01;
	if (keycode == 126)
		mlx->y1 += 0.01;
	if (keycode == 24)
		mlx->zoom += 10;
	if (keycode == 27)
	{
		if (mlx->zoom > 0)
			mlx->zoom -= 10;
	}
	if (keycode == 29)
		mlx->max++;
	if (keycode == 25)
	{
		if (mlx->max > 0)
			mlx->max--;
	}
	return (mlx);
}

int		key(int keycode, t_mlx *mlx)
{
	int		i;

	i = 0;
	ft_putnbr(keycode);
	mlx->img->addr = ft_memset(mlx->img->addr, 0, mlx->w * mlx->h * 4 - 1);
	if (keycode == 53)
		str_exit(0, "ESC !");
	mlx = key_yolo(keycode, mlx);
	mlx = key_color(keycode, mlx);
	draw(mlx);
	return (0);
}
