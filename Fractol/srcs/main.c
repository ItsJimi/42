/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/20 17:28:36 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac < 2)
		str_exit(-1, "Usage : ./fractol <mandelbrot>");
	if (ac > 2)
		str_exit(-1, "Usage : ./fractol <mandelbrot>");
	if (!(mlx = (t_mlx *)malloc(sizeof(*mlx))))
		str_exit(-1, "main.c : Error line 23");
	if (!(ft_strcmp(av[1], "mandelbrot")))
		mlx = new_mlx(mlx, 1, av[1]);
	else
		str_exit(-1, "Usage : ./fractol <mandelbrot>");
	ft_putstr("Chargement ...\n");
	draw(mlx);
	mlx_hook(mlx->win, 2, 0, key, mlx);
	mlx_hook(mlx->win, 4, 0, mouse, mlx);
	//mlx_hook(mlx->win, 6, 0, click, mlx);
	mlx_loop(mlx->mlx);
}
