/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:28:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/19 15:01:11 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		mouse(int x, int y, t_mlx *mlx)
{
	y = 0;
	mlx->imgview->addr = ft_memset(mlx->imgview->addr, 0, mlx->w *
	mlx->h * 4 - 1);
	if (x > mlx->w / 2)
		mlx->deg += 2;
	else if (x < mlx->w / 2)
		mlx->deg -= 2;
	draw(mlx);
	return (0);
}
