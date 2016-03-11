/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:33:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/11 20:10:22 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
	point->color = 0xffffff;
	//point->savecolor = point->color;
	free(z);
	return (point);
}

t_img	*new_img(t_mlx *mlx, int width, int height)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		str_exit(-1, "new.c : Error line 55");
	img->img = mlx_new_image(mlx->mlx, width, height);
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
	mlx->imgview = new_img(mlx, mlx->w, mlx->h);
	mlx->imgmap = new_img(mlx, 190, 190);
	mlx->av = av;
	mlx->deg = 90;
	mlx->menu = 0;
	mlx->map = 0;
	return (mlx);
}
