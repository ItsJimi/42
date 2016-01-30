/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/30 16:28:44 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		str_exit(int error, char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(error);
}

void	str_data(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 80, 0, 0xFF00000, "==[ Informations ]==");
	mlx_string_put(mlx->mlx, mlx->win, 0, 40, 0xFFFFFF, "Fichier FdF   :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 40, 0x8f8f8f, mlx->av);
	mlx_string_put(mlx->mlx, mlx->win, 0, 60, 0xFFFFFF, "Decalage X    :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 60, 0x8f8f8f, ft_itoa(mlx->decalx));
	mlx_string_put(mlx->mlx, mlx->win, 0, 80, 0xFFFFFF, "Decalage Y    :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 80, 0x8f8f8f, ft_itoa(mlx->decaly));
	mlx_string_put(mlx->mlx, mlx->win, 0, 100, 0xFFFFFF, "Perspective X :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 100, 0x8f8f8f, ft_itoa(mlx->perspx));
	mlx_string_put(mlx->mlx, mlx->win, 0, 120, 0xFFFFFF, "Perspective Y :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 120, 0x8f8f8f, ft_itoa(mlx->perspy));
	mlx_string_put(mlx->mlx, mlx->win, 0, 140, 0xFFFFFF, "Espace        :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 140, 0x8f8f8f, ft_itoa(mlx->space));
	mlx_string_put(mlx->mlx, mlx->win, 0, 160, 0xFFFFFF, "Hauteur       :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 160, 0x8f8f8f, ft_itoa(mlx->dim));
	mlx_string_put(mlx->mlx, mlx->win, 80, 200, 0xFF00000, "==[   Touches   ]==");
	mlx_string_put(mlx->mlx, mlx->win, 0, 240, 0xFFFFFF, "Quitter       :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 240, 0x8f8f8f, "Echape");
	mlx_string_put(mlx->mlx, mlx->win, 0, 260, 0xFFFFFF, "Deplacement   :");
	mlx_string_put(mlx->mlx, mlx->win, 160, 260, 0x8f8f8f, "Fleches");

}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac < 2)
		str_exit(-1, "No file");
	if (ac > 2)
		str_exit(-1, "To many arguments");
	mlx = new_mlx(2560, 1440, "F D F", av[1]);
	mlx->p = parse(av[1]);
	mlx->p = dep_point(mlx, mlx->p);
	draw_point(mlx, mlx->p);
	mlx_hook(mlx->win, 2, 0, key, mlx);
	mlx_loop(mlx->mlx);
}
