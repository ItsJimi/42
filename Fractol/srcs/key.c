/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:23:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/19 17:07:00 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear(t_mlx *mlx)
{
	mlx->x1 = -2;
	mlx->x2 = -2 + 4 * mlx->w / mlx->h;
	mlx->y1 = -2;
	mlx->y2 = 2;
	mlx->zoom = 100;
	mlx->max = 50;
}

t_mlx	*key_color(int keycode, t_mlx *mlx)
{
	if (keycode == 82)
		mlx->change_color = rand();
	if (keycode == 83)
		mlx->change_color = 8;
	if (keycode == 84)
		mlx->change_color = 8;
	if (keycode == 85)
		mlx->change_color = 8;
	if (keycode == 86)
		mlx->change_color = 8;
	if (keycode == 51)
		clear(mlx);
	if (keycode == 88)
		mlx->change_color = 8;
	if (keycode == 89)
		mlx->change_color = 8;
	if (keycode == 91)
		mlx->change_color = 8;
	if (keycode == 92)
		mlx->change_color = 0xf0f0f0;
	if (keycode == 87)
		mlx->change_color = 0x0f0f0f;
	if (keycode == 65)
		mlx->change_color = 0x000000;
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
	if (keycode == 69)
		mlx->zoom += 10;
	if (keycode == 78)
		mlx->zoom -= 10;
	if (keycode == 67)
		mlx->max++;
	if (keycode == 75)
		mlx->max--;
	return (mlx);
}

int		key(int keycode, t_mlx *mlx)
{
	ft_putnbr(keycode);
	mlx->img->addr = ft_memset(mlx->img->addr, 0, mlx->w * mlx->h * 4 - 1);
	if (keycode == 53)
	 	str_exit(0, "ESC !");
	// if (keycode == 115)
	// {
	// 	if (mlx->menu == 1)
	// 		mlx->menu = 0;
	// 	else
	// 		mlx->menu = 1;
	// }
	mlx = key_yolo(keycode, mlx);
	mlx = key_color(keycode, mlx);
	draw(mlx);
	return (0);
}
