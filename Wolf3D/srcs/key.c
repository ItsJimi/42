/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:23:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/21 18:54:28 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	key_cross(int keycode, t_mlx *mlx, float a, float b)
{
	if ((keycode == 123 || keycode == 12) && mlx->p[(int)(mlx->beginy + a
	* 3)][(int)(mlx->beginx - b * 3)]->z != 1)
	{
		mlx->beginx -= b;
		mlx->beginy += a;
	}
	if ((keycode == 124 || keycode == 14) && mlx->p[(int)(mlx->beginy - a
	* 3)][(int)(mlx->beginx + b * 3)]->z != 1)
	{
		mlx->beginx += b;
		mlx->beginy -= a;
	}
	if ((keycode == 125 || keycode == 1) && mlx->p[(int)(mlx->beginy + b *
	3)][(int)(mlx->beginx + a * 3)]->z != 1)
	{
		mlx->beginx += a;
		mlx->beginy += b;
	}
	if ((keycode == 126 || keycode == 13) && mlx->p[(int)(mlx->beginy - b *
	3)][(int)(mlx->beginx - a * 3)]->z != 1)
	{
		mlx->beginx -= a;
		mlx->beginy -= b;
	}
}

static void	key_dep(int keycode, t_mlx *mlx)
{
	float	a;
	float	b;

	a = cos(mlx->deg * (PI / 180)) / 4;
	b = sin(mlx->deg * (PI / 180)) / 4;
	key_cross(keycode, mlx, a, b);
	if (keycode == 0)
		mlx->deg -= 5;
	if (keycode == 2)
		mlx->deg += 5;
}

static void	key_opt(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		str_exit(0, "ESC !", mlx);
}

int			key(int keycode, t_mlx *mlx)
{
	mlx->imgview->addr = ft_memset(mlx->imgview->addr, 0, mlx->w * mlx->h * 4
	- 1);
	mlx->imgmap->addr = ft_memset(mlx->imgmap->addr, 0, mlx->mapw * mlx->maph *
	4 - 1);
	key_opt(keycode, mlx);
	key_dep(keycode, mlx);
	draw(mlx);
	return (0);
}
