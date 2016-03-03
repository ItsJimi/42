/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:41:20 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/03 20:47:39 by jmaiquez         ###   ########.fr       */
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
	mlx_string_put(mlx->mlx, mlx->win, 0, 0, 0x6752d9,
		"=========[ Informations ]=========");
}

void	str_menu_key(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 0, 200, 0x6752d9,
		"=========[    Touches   ]=========");
	mlx_string_put(mlx->mlx, mlx->win, 0, 240, 0xFFFFFF, "Quitter       :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 240, 0x8f8f8f, "Echap");
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
		mlx_string_put(mlx->mlx, mlx->win, 0, 0, 0xFFFFFF, "Quitter :");
		mlx_string_put(mlx->mlx, mlx->win, 100, 0, 0x8f8f8f, "Echap");
		mlx_string_put(mlx->mlx, mlx->win, 0, 20, 0xFFFFFF, "Menu    :");
		mlx_string_put(mlx->mlx, mlx->win, 100, 20, 0x8f8f8f, "Home");
	}
}
