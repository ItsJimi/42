/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:23:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/14 20:02:02 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_mlx	*key_dep(int keycode, t_mlx *mlx)
{
	if ((keycode == 123 || keycode == 12) &&
		mlx->p[(int)mlx->beginy][(int)(mlx->beginx - 0.3)]->z != 1)
		mlx->beginx -= 0.3;
	if ((keycode == 124 || keycode == 14) &&
		mlx->p[(int)mlx->beginy][(int)(mlx->beginx + 0.3)]->z != 1)
		mlx->beginx += 0.3;
	if ((keycode == 125 || keycode == 1) &&
		mlx->p[(int)(mlx->beginy + 0.3)][(int)mlx->beginx]->z != 1)
		mlx->beginy += 0.3;
	if ((keycode == 126 || keycode == 13) &&
		mlx->p[(int)(mlx->beginy - 0.3)][(int)mlx->beginx]->z != 1)
		mlx->beginy -= 0.3;
	if (keycode == 0)
		mlx->deg -= 10;
	if (keycode == 2)
		mlx->deg += 10;
	return (mlx);
}

static t_mlx		*key_opt(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		str_exit(0, "ESC !");
	if (keycode == 115)
		mlx->menu = (mlx->menu == 1) ? 0 : 1;
	if (keycode == 46)
		mlx->map = (mlx->map == 1) ? 0 : 1;
	return (mlx);
}

int				key(int keycode, t_mlx *mlx)
{
	mlx->imgview->addr = ft_memset(mlx->imgview->addr, 0, mlx->w * mlx->h * 4 -
	1);
	if (mlx->map == 1)
	{
		mlx->imgmap->addr = ft_memset(mlx->imgmap->addr, 0, mlx->mapw *
			mlx->maph * 4 - 1);
	}
	mlx = key_opt(keycode, mlx);
	mlx = key_dep(keycode, mlx);
	draw(mlx);
	return (0);
}
