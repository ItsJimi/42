/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:33:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/19 13:20:48 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	mlx->w = 500;
	mlx->h = 500;
	mlx->av = av;
	mlx->x1 = -2;
	mlx->x2 = -2 + 4 * mlx->w / mlx->h;
	mlx->y1 = -2;
	mlx->y2 = 2;
	mlx->zoom = 100;
	mlx->max = 50;
	if (!(mlx->mlx = mlx_init()))
		str_exit(-1, "new.c : Error line 34");
	if (!(mlx->win = mlx_new_window(mlx->mlx, mlx->w, mlx->h, "F R A C T O L")))
		str_exit(-1, "new.c : Error line 36");
	mlx->img = new_img(mlx);
	return (mlx);
}
