/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:28:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/21 18:04:23 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			move(int x, int y, t_mlx *mlx)
{
	if (mlx->av == 2 && mlx->mouse_on == 1)
	{
		mlx->img->addr = ft_memset(mlx->img->addr, 0, mlx->w * mlx->h * 4 - 1);
		mlx->mousex = (double)x / ((double)mlx->w / (mlx->x2 - mlx->x1)) +
		mlx->x1;
		mlx->mousey = (double)y / ((double)mlx->h / (mlx->y2 - mlx->y1)) +
		mlx->y1;
		draw(mlx);
	}
	else if (mlx->av == 6 && mlx->mouse_on == 1)
	{
		mlx->img->addr = ft_memset(mlx->img->addr, 0, mlx->w * mlx->h * 4 - 1);
		mlx->mousex = x;
		mlx->mousey = y;
		draw(mlx);
	}
	return (0);
}
