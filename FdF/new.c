/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:33:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/30 16:25:36 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_point	*new_point(int x, int y, char *z)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		str_exit(-1, "new.c : Error line 19");
	point->x = x;
	point->y = y;
	point->z = ft_atoi(z);
	point->color = find_color(z);
	return (point);
}

t_img	*new_img(t_mlx *mlx)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		str_exit(-1, "new.c : Error line 55");
	img->bpp = 0;
	img->size_l = 0;
	img->endian = 0;
	img->img = mlx_new_image(mlx->mlx, 2560, 1440);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}

t_mlx	*new_mlx(int sx, int sy, char *t, char *av)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(*mlx))))
		str_exit(-1, "new.c : Error line 32");
	if (!(mlx->mlx = mlx_init()))
		str_exit(-1, "new.c : Error line 34");
	mlx->img = new_img(mlx);
	if (!(mlx->win = mlx_new_window(mlx->mlx, sx, sy, t)))
		str_exit(-1, "new.c : Error line 36");
	mlx->decalx = 300;
	mlx->decaly = 300;
	mlx->perspx = 0;
	mlx->perspy = 0;
	mlx->space = 1;
	mlx->dim = 0;
	mlx->erasing = 0;
	mlx->av = av;
	mlx->change_color = 11;
	return (mlx);
}