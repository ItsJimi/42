/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:41:20 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/16 14:14:16 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		str_exit(int error, char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(error);
}

/*void	str_menu_data(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 0, 0, 0x6752d9,
		"=========[ Informations ]=========");
	mlx_string_put(mlx->mlx, mlx->win, 0, 40, 0xFFFFFF, "Fichier FdF   :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 40, 0x8f8f8f, mlx->av);
	mlx_string_put(mlx->mlx, mlx->win, 0, 60, 0xFFFFFF, "Decalage X    :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 60, 0x8f8f8f, ft_itoa(mlx->decalx));
	mlx_string_put(mlx->mlx, mlx->win, 0, 80, 0xFFFFFF, "Decalage Y    :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 80, 0x8f8f8f, ft_itoa(mlx->decaly));
	mlx_string_put(mlx->mlx, mlx->win, 0, 100, 0xFFFFFF, "Perspective X :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 100, 0x8f8f8f,
		ft_itoa(mlx->perspx));
	mlx_string_put(mlx->mlx, mlx->win, 0, 120, 0xFFFFFF, "Perspective Y :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 120, 0x8f8f8f,
		ft_itoa(mlx->perspy));
	mlx_string_put(mlx->mlx, mlx->win, 0, 140, 0xFFFFFF, "Espace        :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 140, 0x8f8f8f, ft_itoa(mlx->space));
	mlx_string_put(mlx->mlx, mlx->win, 0, 160, 0xFFFFFF, "Hauteur       :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 160, 0x8f8f8f, ft_itoa(mlx->dim));
}

void	str_menu_key(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 0, 200, 0x6752d9,
		"=========[    Touches   ]=========");
	mlx_string_put(mlx->mlx, mlx->win, 0, 240, 0xFFFFFF, "Quitter       :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 240, 0x8f8f8f, "Echap");
	mlx_string_put(mlx->mlx, mlx->win, 0, 260, 0xFFFFFF, "Deplacement   :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 260, 0x8f8f8f, "Fleches");
	mlx_string_put(mlx->mlx, mlx->win, 0, 280, 0xFFFFFF, "Couleurs      :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 280, 0x8f8f8f, "Pave Num");
	mlx_string_put(mlx->mlx, mlx->win, 0, 300, 0xFFFFFF, "Taille        :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 300, 0x8f8f8f, "* | /");
	mlx_string_put(mlx->mlx, mlx->win, 0, 320, 0xFFFFFF, "Hauteur       :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 320, 0x8f8f8f, "+ | -");
	mlx_string_put(mlx->mlx, mlx->win, 0, 340, 0xFFFFFF, "Perspective   :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 340, 0x8f8f8f, "F16~F19");
	mlx_string_put(mlx->mlx, mlx->win, 0, 360, 0xFFFFFF, "Reinitialiser :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 360, 0x8f8f8f, "Clear");
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
	mlx_string_put(mlx->mlx, mlx->win, 0, mlx->h - 20, 0x8f8f8f,
		"FdF by jmaiquez <jmaiquez@student.42.fr>");
}*/
