/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:20:43 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/23 16:01:26 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		line(t_mlx *mlx, float length, float deg)
{
	float	ca;
	float	sa;
	float	x;
	float	y;

	ca = cos(deg * (PI / 180)) / 500;
	sa = sin(deg * (PI / 180)) / 500;
	length *= 1;
	x = mlx->beginx + 0.1;
	y = mlx->beginy + 0.1;
	while (mlx->p[(int)y][(int)x]->z != 1 && mlx->p[(int)y][(int)x]->z != 2
	&& mlx->p[(int)y][(int)x]->z != 3 && mlx->p[(int)y][(int)x]->z != 4)
	{
		x -= ca;
		y -= sa;
	}
	mlx->color = get_color(mlx, x, y);
	return (sqrt(pow(x - mlx->beginx, 2) + pow(y - mlx->beginy, 2))
	* cos((mlx->deg - deg) * (PI / 180)));
}
