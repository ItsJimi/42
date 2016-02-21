/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:41:20 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/21 16:13:53 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		str_exit(int error, char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(error);
}

void	str_data(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 0, 0, 0xFFFFFF, "Zoom       :");
	mlx_string_put(mlx->mlx, mlx->win, 130, 0, 0x6752d9, ft_itoa(mlx->zoom));
	mlx_string_put(mlx->mlx, mlx->win, 0, 20, 0xFFFFFF, "Iterations :");
	mlx_string_put(mlx->mlx, mlx->win, 130, 20, 0x6752d9,
		ft_itoa(mlx->max));
}
