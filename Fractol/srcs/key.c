/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:23:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/22 21:01:53 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear(t_mlx *mlx)
{
	mlx->x1 = -1.5;
	mlx->x2 = 1.5;
	mlx->y1 = -1.5;
	mlx->y2 = 1.5;
	mlx->zoom = 1;
	if (mlx->av == 6)
		mlx->max = 1;
	else
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
	if (keycode == 12)
		mlx->av = 1;
	if (keycode == 13)
		mlx->av = 2;
	if (keycode == 14)
		mlx->av = 3;
	if (keycode == 15)
		mlx->av = 4;
	return (mlx);
}

t_mlx	*key_move(int keycode, t_mlx *mlx)
{
	if (keycode == 26)
		mlx->change_color = 7;
	if (keycode == 123)
		mlx->movex += 1 * mlx->zoom;
	if (keycode == 124)
		mlx->movex -= 1 * mlx->zoom;
	if (keycode == 125)
		mlx->movey -= 1 * mlx->zoom;
	if (keycode == 126)
		mlx->movey += 1 * mlx->zoom;
	if (keycode == 24)
		zoom_in(250, 250, mlx);
	if (keycode == 27)
		zoom_out(250, 250, mlx);
	return (mlx);
}

t_mlx	*key_yolo(int keycode, t_mlx *mlx)
{
	t_mlx	*mlx2;

	if (keycode == 258)
	{
		if (!(mlx2 = (t_mlx *)malloc(sizeof(*mlx2))))
			str_exit(-1, "main.c : Error line 23");
		new_window(mlx2, "mandelbrot");
	}
	if (keycode == 17)
	{
		mlx->max = 1;
		mlx->av = 6;
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
	mlx->img->addr = ft_memset(mlx->img->addr, 0, mlx->w * mlx->h * 4 - 1);
	if (keycode == 53)
		str_exit(0, "ESC !");
	if (keycode == 28)
	{
		if (mlx->mouse_on == 0)
			mlx->mouse_on = 1;
		else
			mlx->mouse_on = 0;
	}
	if (keycode == 12 || keycode == 13 || keycode == 14 || keycode == 15
		|| keycode == 15)
	{
		clear(mlx);
	}
	mlx = key_yolo(keycode, mlx);
	mlx = key_move(keycode, mlx);
	mlx = key_color(keycode, mlx);
	draw(mlx);
	return (0);
}
