/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:21:26 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/23 13:01:05 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point	***gnl_error2(t_point ***point, t_mlx *mlx, int error, int y)
{
	mlx->maph = y;
	point[y] = NULL;
	if (mlx->nbrstart != 1)
		str_exit(-1, "** ERROR MAP **", mlx);
	if (mlx->beginx == -1 || mlx->beginy == -1)
		str_exit(-1, "** ERROR MAP **", mlx);
	if (error == 0 && y != 0)
		return (point);
	else
		str_exit(-1, "Error gnl", mlx);
	return (point);
}

int		gnl_error1(char *tab)
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

int		parse_error(t_mlx *mlx, int i, char *line)
{
	if (i == -1)
		i = (int)ft_strlen(line);
	else if (i != (int)ft_strlen(line))
		str_exit(-1, "** ERROR MAP **", mlx);
	return (i);
}

void	wall_error()
{
	int		x;
	int		y;

	y = 0;
	while (y < mlx->maph)
	{
		x = 0;
		while (x < mlx->mapw)
		{
			/* code */
		}
		x++;
	}
}
