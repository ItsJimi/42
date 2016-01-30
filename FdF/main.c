/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/30 18:48:39 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac < 2)
		str_exit(-1, "No file");
	if (ac > 2)
		str_exit(-1, "To many arguments");
	mlx = new_mlx(1500, 1000, "F D F", av[1]);
	mlx->p = parse(av[1]);
	mlx->p = dep_point(mlx, mlx->p);
	draw_point(mlx, mlx->p);
	mlx_hook(mlx->win, 2, 0, key, mlx);
	mlx_loop(mlx->mlx);
}
