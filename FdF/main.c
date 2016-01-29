/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/29 19:31:12 by jmaiquez         ###   ########.fr       */
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
	mlx_string_put(mlx->mlx, mlx->win, 0, 0, 0x333333, mlx->av);
	mlx_string_put(mlx->mlx, mlx->win, 0, 20, 0x333333, ft_itoa(mlx->decalx));
	mlx_string_put(mlx->mlx, mlx->win, 0, 40, 0x333333, ft_itoa(mlx->decaly));
	mlx_string_put(mlx->mlx, mlx->win, 0, 60, 0x333333, ft_itoa(mlx->perspx));
	mlx_string_put(mlx->mlx, mlx->win, 0, 80, 0x333333, ft_itoa(mlx->perspy));
	mlx_string_put(mlx->mlx, mlx->win, 0, 100, 0x333333, ft_itoa(mlx->space));
	mlx_string_put(mlx->mlx, mlx->win, 0, 120, 0x333333, ft_itoa(mlx->dim));
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
