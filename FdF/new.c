/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:33:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/29 19:31:20 by jmaiquez         ###   ########.fr       */
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
	mlx->decalx = 0;
	mlx->decaly = 0;
	mlx->perspx = 0;
	mlx->perspy = 0;
	mlx->space = 1;
	mlx->dim = 0;
	mlx->erasing = 0;
	mlx->av = av;
	mlx->change_color = 1;
	return (mlx);
}
