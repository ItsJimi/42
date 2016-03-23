/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/23 12:29:07 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(*mlx))))
	{
		ft_putstr("ERROR\n");
		exit(-1);
	}
	if (ac > 1 || av[1])
	{
		ft_putstr("No argument needed\n");
		exit(-1);
	}
	ft_putstr("Chargement du niveau ...\n");
	mlx->p = parse("maps/hub", mlx, 0);
	ft_putstr("Chargement termine !\n");
	mlx = new_mlx(mlx);
	draw(mlx);
	mlx_hook(mlx->win, 2, 0, key, mlx);
	mlx_hook(mlx->win, 6, 0, mouse, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
