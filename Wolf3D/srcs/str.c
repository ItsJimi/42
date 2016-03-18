/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:41:20 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/18 19:25:31 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		str_exit(int error, char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(error);
}

void	str_data(t_mlx *mlx)
{
	if (mlx->map == 1)
	{
		mlx_string_put(mlx->mlx, mlx->win, 5, mlx->h - 25, 0x6166F9, "x : ");
		mlx_string_put(mlx->mlx, mlx->win, 45, mlx->h - 25, 0x61F98A,
			ft_itoa((int)mlx->beginx));
		mlx_string_put(mlx->mlx, mlx->win, 105, mlx->h - 25, 0x6166F9, "y : ");
		mlx_string_put(mlx->mlx, mlx->win, 145, mlx->h - 25, 0x61F98A,
			ft_itoa((int)mlx->beginy));
		mlx_string_put(mlx->mlx, mlx->win, 205, mlx->h - 25, 0x6166F9,
			"deg : ");
		mlx_string_put(mlx->mlx, mlx->win, 265, mlx->h - 25, 0x61F98A,
			ft_itoa((int)mlx->deg));
	}
	else
	{
		mlx_string_put(mlx->mlx, mlx->win, 5, mlx->h - 25, 0x8f8f8f,
			"Press M to show map");
	}
	mlx_string_put(mlx->mlx, mlx->win, mlx->w - 205, mlx->h - 25, 0x8f8f8f,
		"Press escape to quit");
}
