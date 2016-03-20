/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:41:20 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/20 17:33:52 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		str_exit(int error, char *str, t_mlx *mlx)
{
	ft_putstr(str);
	ft_putchar('\n');
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(error);
}

void	str_data(t_mlx *mlx)
{
	char	*x;
	char	*y;
	char	*deg;

	x = ft_itoa((int)mlx->beginx);
	y = ft_itoa((int)mlx->beginy);
	deg = ft_itoa((int)mlx->deg);
	mlx_string_put(mlx->mlx, mlx->win, 5, mlx->h - 25, 0x6166F9, "x : ");
	mlx_string_put(mlx->mlx, mlx->win, 45, mlx->h - 25, 0x61F98A, x);
	mlx_string_put(mlx->mlx, mlx->win, 105, mlx->h - 25, 0x6166F9, "y : ");
	mlx_string_put(mlx->mlx, mlx->win, 145, mlx->h - 25, 0x61F98A, y);
	mlx_string_put(mlx->mlx, mlx->win, 205, mlx->h - 25, 0x6166F9, "deg : ");
	mlx_string_put(mlx->mlx, mlx->win, 265, mlx->h - 25, 0x61F98A, deg);
	mlx_string_put(mlx->mlx, mlx->win, mlx->w - 205, mlx->h - 25, 0x8f8f8f,
	"Press escape to quit");
	free(x);
	free(y);
	free(deg);
}
