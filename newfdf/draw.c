/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:28:52 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/27 16:16:48 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		***dep_points(t_mlx *mlx, t_point ***p)
{
	int		i;
	int		j;

	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			(p[i][j])->px = (mlx->decalx) + (mlx->perspx * i) + ((p[i][j])->x +
				(j * mlx->space)) - ((p[i][j])->z * mlx->dim);
			(p[i][j])->py = (mlx->decaly) + (mlx->perspy * j) + ((p[i][j])->y +
				(i * mlx->space)) - ((p[i][j])->z * mlx->dim);
			j++;
		}
		i++;
	}
	return (p);
}

/*void		d_points(t_mlx *mlx, t_point ***p)
{
	int		i;
	int		j;

	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			if (p[i][j + 1])
				d_line(mlx, n_line((p[i][j])->px, (p[i][j])->py,
					(p[i][j + 1])->px, (p[i][j + 1])->py),
					mlx->erasing ? 0x00000000 : p[i][j]->color);
			if (p[i + 1] && p[i + 1][j])
				d_line(mlx, n_line((p[i][j])->px, (p[i][j])->py,
					(p[i + 1][j])->px, (p[i + 1][j])->py),
					mlx->erasing ? 0x00000000 : p[i][j]->color);
			j++;
		}
		i++;
	}
	//mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, 0, 350, 0xFFFFFF, "===[ F D F ]===");
}*/
