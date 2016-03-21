/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:33:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/21 16:12:56 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point	*new_point(int x, int y, char *z, t_mlx *mlx)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		str_exit(-1, "new.c : Error line 52", mlx);
	point->x = x;
	point->y = y;
	point->z = ft_atoi(z);
	if (point->z == 42)
	{
		mlx->beginx = x;
		mlx->beginy = y;
	}
	return (point);
}

t_img	*new_xpm(t_mlx *mlx, int w, int h)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		str_exit(-1, "new.c : Error line 55", mlx);
	if (!(img->img = mlx_xpm_file_to_image(mlx->mlx, "skybox.xpm", &w, &h)))
		str_exit(-1, "No skybox", mlx);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}

t_img	*new_img(t_mlx *mlx, int width, int height)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		str_exit(-1, "new.c : Error line 55", mlx);
	img->img = mlx_new_image(mlx->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}

t_mlx	*new_mlx(t_mlx *mlx)
{
	mlx->w = 1285;
	mlx->h = 725;
	if (!(mlx->mlx = mlx_init()))
	{
		ft_putstr("ERROR\n");
		exit(-1);
	}
	if (!(mlx->win = mlx_new_window(mlx->mlx, mlx->w, mlx->h, "W O L F 3 D")))
	{
		ft_putstr("ERROR\n");
		exit(-1);
	}
	mlx->imgsky = new_xpm(mlx, mlx->w, mlx->h);
	mlx->imgview = new_img(mlx, mlx->w, mlx->h);
	mlx->imgmap = new_img(mlx, mlx->mapw * 10, mlx->maph * 10);
	mlx->deg = 90;
	return (mlx);
}
