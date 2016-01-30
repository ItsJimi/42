/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:23:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/30 14:23:01 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < 1440)
	{
		x = 0;
		while (x < 2560)
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
	return (mlx);
}

int		key(int keycode, t_mlx *mlx)
{
	reset(mlx);
	ft_putstr("KEYCODE : ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 53)
		str_exit(0, "ESC !");
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
	mlx = key_color(keycode, mlx);
	mlx->p = dep_point(mlx, mlx->p);
	draw_point(mlx, mlx->p);
	return (0);
}