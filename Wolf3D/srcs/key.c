/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 12:53:24 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/04/01 12:53:31 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	key1(int keycode, t_mlx *mlx, float a, float b)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (a < 0)
		x = -1;
	if (b < 0)
		y = -1;
	if ((keycode == 123 || keycode == 12) && mlx->p[(int)(mlx->beginy +
	a)][(int)(mlx->beginx - b)]->z != 1 && mlx->p[(int)(mlx->beginy + a *
	3)][(int)(mlx->beginx - b * 3)]->z != 1 && mlx->p[(int)(mlx->beginy)]
	[(int)(mlx->beginx - b - y * 0.1)]->z != 1 && mlx->p[(int)(mlx->beginy +
	a + x * 0.1)][(int)(mlx->beginx)]->z != 1)
	{
		mlx->beginx -= b;
		mlx->beginy += a;
	}
}

static void	key2(int keycode, t_mlx *mlx, float a, float b)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (a < 0)
		x = -1;
	if (b < 0)
		y = -1;
	if ((keycode == 124 || keycode == 14) && mlx->p[(int)(mlx->beginy -
	a)][(int)(mlx->beginx + b)]->z != 1 && mlx->p[(int)(mlx->beginy - a *
	3)][(int)(mlx->beginx + b * 3)]->z != 1 && mlx->p[(int)(mlx->beginy)]
	[(int)(mlx->beginx + b + y * 0.1)]->z != 1 && mlx->p[(int)(mlx->beginy +
	a + x * 0.1)][(int)(mlx->beginx)]->z != 1)
	{
		mlx->beginx += b;
		mlx->beginy -= a;
	}
}

static void	key3(int keycode, t_mlx *mlx, float a, float b)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (a < 0)
		x = -1;
	if (b < 0)
		y = -1;
	if ((keycode == 125 || keycode == 1) && mlx->p[(int)(mlx->beginy +
	b)][(int)(mlx->beginx + a)]->z != 1 && mlx->p[(int)(mlx->beginy + b *
	3)][(int)(mlx->beginx + a * 3)]->z != 1 && mlx->p[(int)(mlx->beginy)]
	[(int)(mlx->beginx + a + x * 0.1)]->z != 1 && mlx->p[(int)(mlx->beginy +
	b + y * 0.1)][(int)(mlx->beginx)]->z != 1)
	{
		mlx->beginx += a;
		mlx->beginy += b;
	}
}

static void	key4(int keycode, t_mlx *mlx, float a, float b)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (a < 0)
		x = -1;
	if (b < 0)
		y = -1;
	if ((keycode == 126 || keycode == 13) && mlx->p[(int)(mlx->beginy -
	b)][(int)(mlx->beginx - a)]->z != 1 && mlx->p[(int)(mlx->beginy - b *
	3)][(int)(mlx->beginx - a * 3)]->z != 1 && mlx->p[(int)(mlx->beginy)]
	[(int)(mlx->beginx - a - x * 0.1)]->z != 1 && mlx->p[(int)(mlx->beginy -
	b - y * 0.1)][(int)(mlx->beginx)]->z != 1)
	{
		mlx->beginx -= a;
		mlx->beginy -= b;
	}
}

int			key(int keycode, t_mlx *mlx)
{
	float	a;
	float	b;

	mlx->imgview->addr = ft_memset(mlx->imgview->addr, 0, mlx->w * mlx->h * 4
	- 1);
	mlx->imgmap->addr = ft_memset(mlx->imgmap->addr, 0, mlx->mapw * mlx->maph *
	4 - 1);
	a = cos(mlx->deg * (PI / 180)) / 4;
	b = sin(mlx->deg * (PI / 180)) / 4;
	key1(keycode, mlx, a, b);
	key2(keycode, mlx, a, b);
	key3(keycode, mlx, a, b);
	key4(keycode, mlx, a, b);
	if (keycode == 53)
		str_exit(0, "ESC", mlx);
	if (keycode == 0)
		mlx->deg -= 5;
	if (keycode == 2)
		mlx->deg += 5;
	draw(mlx);
	return (0);
}
