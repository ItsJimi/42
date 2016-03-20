/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/20 17:54:44 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		gnl_error(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i] >= 48 && tab[i] <= 57)
			j++;
		i++;
	}
	if (j == 0)
		return (-1);
	return (0);
}

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
