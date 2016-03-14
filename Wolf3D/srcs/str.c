/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:41:20 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/14 16:54:22 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		str_exit(int error, char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(error);
}

void	str_menu_data(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 500, 0, 0x6752d9,
		"=========[ Informations ]=========");
}

void	str_menu_key(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 500, 200, 0x6752d9,
		"=========[    Touches   ]=========");
	mlx_string_put(mlx->mlx, mlx->win, 500, 240, 0xFFFFFF, "Quitter       :");
	mlx_string_put(mlx->mlx, mlx->win, 660, 240, 0x8f8f8f, "Echap");
}

void	str_data(t_mlx *mlx)
{
	if (mlx->menu == 1)
	{
		str_menu_data(mlx);
		str_menu_key(mlx);
	}
	else
	{
		mlx_string_put(mlx->mlx, mlx->win, 500, 0, 0xFFFFFF, "Quitter :");
		mlx_string_put(mlx->mlx, mlx->win, 600, 0, 0x8f8f8f, "Echap");
		mlx_string_put(mlx->mlx, mlx->win, 500, 20, 0xFFFFFF, "Menu    :");
		mlx_string_put(mlx->mlx, mlx->win, 600, 20, 0x8f8f8f, "Home");
	}
}
