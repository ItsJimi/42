/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:28:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/19 14:10:52 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse(int x, int y, t_mlx *mlx)
{
	mlx->img->addr = ft_memset(mlx->img->addr, 0, mlx->w * mlx->h * 4 - 1);
	mlx->deg += 1;
	draw(mlx);
	return (0);
}
