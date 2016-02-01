/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/01 18:28:37 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac < 2)
		str_exit(-1, "No file");
	if (ac == 2)
	{
		av[2] = "2560";
		av[3] = "1395";
	}
	if (ac > 4)
		str_exit(-1, "To many arguments");
	if (!(mlx = (t_mlx *)malloc(sizeof(*mlx))))
		str_exit(-1, "new.c : Error line 32");
	ft_putstr("Chargement de la carte ...\n");
	mlx->p = parse(av[1]);
	ft_putstr("Chargement termine !\n");
	mlx = new_mlx(mlx, av[1], ft_atoi(av[2]), ft_atoi(av[3]));
	mlx->p = dep_point(mlx, mlx->p);
	draw_point(mlx, mlx->p);
	mlx_hook(mlx->win, 2, 0, key, mlx);
	mlx_loop(mlx->mlx);
}
