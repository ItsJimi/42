/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:33:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/02 18:45:11 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		atoi_color(char *z)
{
	int		i;
	int		color;

	i = 3;
	color = 1;
	while (z[i] != '\0')
	{
		if (z[i] >= 48 && z[i] <= 57)
			color = color * 16 + z[i] - 48;
		else if (z[i] >= 65 && z[i] <= 70)
			color = color * 16 + z[i] - 55;
		else
			return (0xFFFFFF);
		i++;
	}
	return (color);
}

int		find_color(char *z)
{
	int		i;

	i = 0;
	while (z[i] != ',' && z[i] != ' ' && z[i] != '\0')
		i++;
	if (z[i] != ',')
		return (0xFFFFFF);
	return (atoi_color(z + i));
}

t_point	*new_point(int x, int y, char *z, t_mlx *mlx)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		str_exit(-1, "new.c : Error line 52");
	point->x = x;
	point->y = y;
	point->z = ft_atoi(z);
	if (point->z == 42)
	{
		mlx->beginx = x;
		mlx->beginy = y;
	}
	point->color = find_color(z);
	point->savecolor = point->color;
	free(z);
	return (point);
}

t_img	*new_img(t_mlx *mlx)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		str_exit(-1, "new.c : Error line 55");
	img->img = mlx_new_image(mlx->mlx, mlx->w, mlx->h);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}

t_mlx	*new_mlx(t_mlx *mlx, char *av)
{
	mlx->w = 1280;
	mlx->h = 720;
	if (!(mlx->mlx = mlx_init()))
		str_exit(-1, "new.c : Error line 83");
	if (!(mlx->win = mlx_new_window(mlx->mlx, mlx->w, mlx->h, "W O L F 3 D")))
		str_exit(-1, "new.c : Error line 86");
	mlx->img = new_img(mlx);
	mlx->decalx = 300;
	mlx->decaly = 300;
	mlx->perspx = 0;
	mlx->perspy = 0;
	mlx->space = 10;
	mlx->dim = 3;
	mlx->erasing = 0;
	mlx->av = av;
	mlx->menu = 0;
	return (mlx);
}
