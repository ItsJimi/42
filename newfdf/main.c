/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/27 19:28:50 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		str_exit(int error, char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(error);
}

t_point	*new_point(int x, int y, int z)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		str_exit(-1, "Error");
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_mlx	*n_mlx(int sx, int sy, char *t)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(*mlx))))
		str_exit(-1, "Error 1");
	if (!(mlx->mlx = mlx_init()))
		str_exit(-1, "Error 2");
	if (!(mlx->win = mlx_new_window(mlx->mlx, sx, sy, t)))
		str_exit(-1, "Error 3");
	//mlx->img = n_img(mlx);
	mlx->decalx = 100;
	mlx->decaly = 100;
	mlx->perspx = 0;
	mlx->perspy = 0;
	mlx->space = 20;
	mlx->dim = 3;
	mlx->erasing = 0;
	return (mlx);
}

int		key(int keycode)
{
	ft_putstr("KEYCODE : ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 53)
		str_exit(0, "ESC !");
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2)
		str_exit(-1, "No file");
	mlx = n_mlx(1000, 1000, "F D F");
	mlx->p = parse(av[1]);
	mlx->p = dep_points(mlx, mlx->p);
	d_points(mlx, mlx->p);
	mlx_hook(mlx->win, 2, 0, key, 0);
	mlx_loop(mlx->mlx);
}
