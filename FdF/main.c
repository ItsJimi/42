/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/28 11:32:15 by jmaiquez         ###   ########.fr       */
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
		str_exit(-1, "main.c : Error line 26");
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = 0xFFFFFF;
	return (point);
}

t_mlx	*n_mlx(int sx, int sy, char *t)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(*mlx))))
		str_exit(-1, "main.c : Error line 39");
	if (!(mlx->mlx = mlx_init()))
		str_exit(-1, "main.c : Error line 41");
	if (!(mlx->win = mlx_new_window(mlx->mlx, sx, sy, t)))
		str_exit(-1, "main.c : Error line 43");
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

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac < 2)
		str_exit(-1, "No file");
	if (ac > 2)
		str_exit(-1, "To many arguments");
	mlx = n_mlx(1000, 1000, "F D F");
	mlx->p = parse(av[1]);
	mlx->p = dep_point(mlx, mlx->p);
	draw_point(mlx, mlx->p);
	mlx_hook(mlx->win, 2, 0, key, mlx);
	mlx_loop(mlx->mlx);
}
