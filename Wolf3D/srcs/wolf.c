/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:20:43 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/05 17:25:29 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		line(t_mlx *mlx, float length)
{
	float	xy2[2];
	float	x;
	float	y;
	float	dx;
	float	dy;

	xy2[0] = cos(90 * (PI / 180)) * 100;
	xy2[1] = sin(90 * (PI / 180)) * 100;
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
		x += dx;
		y += dy;
	}
	return (sqrt(pow(xy2[0] - mlx->beginx, 2) + pow(xy2[1] - mlx->beginy, 2)));
}
