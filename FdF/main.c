/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/27 20:58:56 by jmaiquez         ###   ########.fr       */
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
	point->color = 0xFFFFFF;
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

int		key(int keycode, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_putstr("KEYCODE : ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 53)
		str_exit(0, "ESC !");
	if (keycode == 123)
		mlx->decalx -= 10;
	if (keycode == 124)
		mlx->decalx += 10;
	if (keycode == 125)
		mlx->decaly += 10;
	if (keycode == 126)
		mlx->decaly -= 10;
	if (keycode == 69)
		mlx->dim++;
	if (keycode == 78)
		mlx->dim--;
	if (keycode == 67)
		mlx->space++;
	if (keycode == 75)
		mlx->space--;
	if (keycode == 106)
		mlx->perspx++;
	if (keycode == 64)
		mlx->perspx--;
	if (keycode == 79)
		mlx->perspy++;
	if (keycode == 80)
		mlx->perspy--;
	mlx->p = dep_points(mlx, mlx->p);
	d_points(mlx, mlx->p);
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
	mlx_hook(mlx->win, 2, 0, key, mlx);
	mlx_loop(mlx->mlx);
}
