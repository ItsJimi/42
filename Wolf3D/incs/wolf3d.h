/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:51:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/14 19:06:59 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define PI 3.14159265359

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_point
{
	int			px;
	int			py;

	int			x;
	int			y;
	int			z;

	int			color;
}				t_point;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	char		*av;

	int			w;
	int			h;

	int			mapw;
	int			maph;

	float		beginx;
	float		beginy;
	float		deg;

	t_point		***p;
	t_img		*imgview;
	t_img		*imgmap;

	int			menu;
	int			map;
}				t_mlx;

float			line(t_mlx *mlx, float length, float deg);
t_point			***parse(char *av, t_mlx *mlx);
t_point			*new_point(int x, int y, char *z, t_mlx *mlx);
t_mlx			*new_mlx(t_mlx *mlx, char *av);
t_img			*new_img(t_mlx *mlx, int width, int height);
void			draw_img_view(t_mlx *mlx, int color, int x, int y);
void			draw_img_map(t_mlx *mlx, int color, int x, int y);
void			draw(t_mlx *mlx);
void			drawx(t_mlx *mlx);
void			map(t_mlx *mlx);
int				str_exit(int error, char *str);
int				key(int keycode, t_mlx *mlx);
void			str_data(t_mlx *mlx);
int				gnl_error(char *tab);

#endif
