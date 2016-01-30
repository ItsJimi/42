/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:23:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/30 19:23:03 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1500)
		{
			draw_img(mlx, 0x000000, x, y);
			x++;
		}
		y++;
	}
}

t_mlx	*key_color(int keycode, t_mlx *mlx)
{
	if (keycode == 82)
		mlx->change_color = 0;
	if (keycode == 83)
		mlx->change_color = 1;
	if (keycode == 84)
		mlx->change_color = 2;
	if (keycode == 85)
		mlx->change_color = 3;
	if (keycode == 86)
		mlx->change_color = 4;
	if (keycode == 71)
		mlx->change_color = 5;
	if (keycode == 88)
		mlx->change_color = 6;
	if (keycode == 89)
		mlx->change_color = 7;
	if (keycode == 91)
		mlx->change_color = 8;
	if (keycode == 92)
		mlx->change_color = 9;
	if (keycode == 65)
		mlx->change_color = 10;
	if (keycode == 87)
		mlx->change_color = 11;
	return (mlx);
}

t_mlx	*key_yolo(int keycode, t_mlx *mlx)
{
	if (keycode == 123)
		mlx->decalx -= 10;
	if (keycode == 124)
		mlx->decalx += 10;
	if (keycode == 125)
		mlx->decaly += 10;
	if (keycode == 126)
		mlx->decaly -= 10;
	if (keycode == 69)
		mlx->dim++;
	if (keycode == 78)
		mlx->dim--;
	if (keycode == 67)
		mlx->space++;
	if (keycode == 75)
		mlx->space--;
	if (keycode == 106)
		mlx->perspx++;
	if (keycode == 64)
		mlx->perspx--;
	if (keycode == 79)
		mlx->perspy++;
	if (keycode == 80)
		mlx->perspy--;
	return (mlx);
}

int		key(int keycode, t_mlx *mlx)
{
	reset(mlx);
	if (keycode == 53)
		str_exit(0, "ESC !");
	if (keycode == 115)
	{
		if (mlx->menu == 1)
			mlx->menu = 0;
		else
			mlx->menu = 1;
	}
	mlx = key_yolo(keycode, mlx);
	mlx = key_color(keycode, mlx);
	mlx->p = dep_point(mlx, mlx->p);
	draw_point(mlx, mlx->p);
	return (0);
}
