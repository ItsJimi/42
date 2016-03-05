/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:23:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/05 17:22:57 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_mlx	*key_dep(int keycode, t_mlx *mlx)
{
	if (keycode == 123 && mlx->p[mlx->beginy][mlx->beginx - 1]->z != 1)
		mlx->beginx--;
	if (keycode == 124 && mlx->p[mlx->beginy][mlx->beginx + 1]->z != 1)
		mlx->beginx++;
	if (keycode == 125 && mlx->p[mlx->beginy - 1][mlx->beginx]->z != 1)
		mlx->beginy--;
	if (keycode == 126 && mlx->p[mlx->beginy + 1][mlx->beginx]->z != 1)
		mlx->beginy++;
	return (mlx);
}

int				key(int keycode, t_mlx *mlx)
{
	mlx->img->addr = ft_memset(mlx->img->addr, 0, 2560 * 1400 * 4 - 1);
	if (keycode == 53)
		str_exit(0, "ESC !");
	if (keycode == 115)
	{
		if (mlx->menu == 1)
			mlx->menu = 0;
		else
			mlx->menu = 1;
	}
	mlx = key_dep(keycode, mlx);
	draw(mlx);
	return (0);
}
