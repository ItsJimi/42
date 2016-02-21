/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:33:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/21 11:32:55 by jmaiquez         ###   ########.fr       */
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

char	*str_maj(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s) * 2) + 1));
	while (s[i])
	{
		str[j] = ft_toupper(s[i]);
		str[j + 1] = ' ';
		j += 2;
		i++;
	}
	str[j - 1] = '\0';
	return (str);
}

t_line	*new_line(int x1, int y1, int x2, int y2)
{
	t_line	*line;

	if (!(line = (t_line *)malloc(sizeof(*line))))
		str_exit(-1, "new.c : Error line 51")
	line->x1 = x1;
	line->y1 = y1;
	line->x2 = x2;
	line->y2 = y2;
	return (line);
}

t_mlx	*new_mlx(t_mlx *mlx, int av, char *name)
{
	mlx->w = 500;
	mlx->h = 500;
	mlx->av = av;
	mlx->menu = 0;
	mlx->x1 = -2;
	mlx->x2 = -2 + 4 * mlx->w / mlx->h;
	mlx->y1 = -1.2;
	mlx->y2 = 2;
	mlx->zoom = 200;
	mlx->max = 20;
	mlx->change_color = 0;
	if (!(mlx->mlx = mlx_init()))
		str_exit(-1, "new.c : Error line 73");
	if (!(mlx->win = mlx_new_window(mlx->mlx, mlx->w, mlx->h, str_maj(name))))
		str_exit(-1, "new.c : Error line 75");
	mlx->img = new_img(mlx);
	return (mlx);
}
