/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:20:43 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/16 16:41:17 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		line(t_mlx *mlx, float length, float deg)
{
	float	xy2[2];
	float	x;
	float	y;
	float	dx;
	float	dy;

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
	while (mlx->p[(int)y][(int)x]->z != 1)
	{
		x += dx / 500;
		y += dy / 500;
	}
	mlx->color = get_color(mlx, x, y);
	printf("--------------------------------\ndx : %f, dy : %f\n", cos(mlx->deg * (PI / 180)), sin(mlx->deg * (PI / 180)));
	printf("%f - %f - %d\n", mlx->beginx, mlx->beginy, mlx->p[(int)mlx->beginy][(int)mlx->beginx]->z);
	printf("x : %f, y : %f\n", x, y);
	return (sqrt(pow(x - mlx->beginx, 2) + pow(y - mlx->beginy, 2)) *
	cos((mlx->deg - deg) * (PI / 180)));
}
