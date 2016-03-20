/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:20:43 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/20 17:40:46 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		line(t_mlx *mlx, float length, float deg)
{
	float	xy2[2];
	float	dx;
	float	dy;
	float	x;
	float	y;

	xy2[0] = mlx->beginx - (cos(deg * (PI / 180)) * 100 * mlx->mapw);
	xy2[1] = mlx->beginy - (sin(deg * (PI / 180)) * 100 * mlx->maph);
	if (ft_abs(xy2[0] - mlx->beginx) >= ft_abs(xy2[1] - mlx->beginy))
		length = ft_abs(xy2[0] - mlx->beginx);
	else
		length = ft_abs(xy2[1] - mlx->beginy);
	dx = (xy2[0] - mlx->beginx) / length;
	dy = (xy2[1] - mlx->beginy) / length;
	x = mlx->beginx + 0.1;
	y = mlx->beginy + 0.1;
	while (mlx->p[(int)y][(int)x]->z != 1 && mlx->p[(int)y][(int)x]->z != 2
	&& mlx->p[(int)y][(int)x]->z != 3 && mlx->p[(int)y][(int)x]->z != 4)
	{
		x += dx / 500;
		y += dy / 500;
	}
	mlx->color = get_color(mlx, x, y);
	return (sqrt(pow(x - mlx->beginx, 2) + pow(y - mlx->beginy, 2)) *
	cos((mlx->deg - deg) * (PI / 180)));
}
