/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:33:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/28 17:40:01 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*new_point(int x, int y, int z)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		str_exit(-1, "new.c : Error line 19");
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = 0xFFFFFF;
	return (point);
}

t_mlx	*new_mlx(int sx, int sy, char *t, char *av)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(*mlx))))
		str_exit(-1, "new.c : Error line 32");
	if (!(mlx->mlx = mlx_init()))
		str_exit(-1, "new.c : Error line 34");
	if (!(mlx->win = mlx_new_window(mlx->mlx, sx, sy, t)))
		str_exit(-1, "new.c : Error line 36");
	mlx->img = new_img(mlx);
	mlx->decalx = 100;
	mlx->decaly = 100;
	mlx->perspx = 0;
	mlx->perspy = 0;
	mlx->space = 20;
	mlx->dim = 3;
	mlx->erasing = 0;
	mlx->av = av;
	mlx->change_color = 1;
	return (mlx);
}

t_img	*new_img(t_mlx *mlx)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		str_exit(-1, "new.c : Error line 55");
	img->bpp = 0;
	img->sizel = 0;
	img->endn = 0;
	img->img = mlx_new_image(mlx->mlx, 2000, 1000);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->sizel),
		&(img->endn));
	return (img);
}
