/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/21 10:03:54 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choice(t_mlx *mlx, char *av)
{
	if (!(ft_strcmp(av, "mandelbrot")))
		mlx = new_mlx(mlx, 1, av);
	else if (!(ft_strcmp(av, "julia")))
		mlx = new_mlx(mlx, 2, av);
	else if (!(ft_strcmp(av, "burningship")))
		mlx = new_mlx(mlx, 3, av);
	else if (!(ft_strcmp(av, "douady")))
		mlx = new_mlx(mlx, 4, av);
	else if (!(ft_strcmp(av, "buddhabrot")))
		mlx = new_mlx(mlx, 5, av);
	else
		str_exit(-1,
		"Usage : ./fractol <mandelbrot|julia|burningship|douady|buddhabrot>");
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac < 2)
		str_exit(-1,
		"Usage : ./fractol <mandelbrot|julia|burningship|douady|buddhabrot>");
	if (ac > 2)
		str_exit(-1,
		"Usage : ./fractol <mandelbrot|julia|burningship|douady|buddhabrot>");
	if (!(mlx = (t_mlx *)malloc(sizeof(*mlx))))
		str_exit(-1, "main.c : Error line 23");
	choice(mlx, av[1]);
	ft_putstr("Chargement ...\n");
	draw(mlx);
	mlx_hook(mlx->win, 2, 0, key, mlx);
	mlx_hook(mlx->win, 4, 0, mouse, mlx);
	//mlx_hook(mlx->win, 6, 0, click, mlx);
	mlx_loop(mlx->mlx);
}
