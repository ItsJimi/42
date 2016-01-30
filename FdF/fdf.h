/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:51:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/30 15:51:30 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

# include "libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_img
{
	void		*img;
	char		*addr;
	char		*data;
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

	t_point		***p;
	t_img		*img;

	int			decalx;
	int			decaly;

	int			perspx;
	int			perspy;

	int			space;
	int			dim;

	int			erasing;
	int			pos[5];
	int			change_color;
}				t_mlx;

t_point			***parse(char *av);
t_point			*new_point(int x, int y, char *z);
t_mlx			*new_mlx(int sx, int sy, char *t, char *av);
t_img			*new_img(t_mlx *mlx);
t_point			***dep_point(t_mlx *mlx, t_point ***p);
int				draw_line(t_mlx *mlx, int pos[5]);
void			draw_point(t_mlx *mlx, t_point ***p);
int				str_exit(int error, char *str);
int				key(int keycode, t_mlx *mlx);
void			str_data(t_mlx *mlx);
void			draw_img(t_mlx *mlx, int color, int x, int y);
int				find_color(char *z);

#endif
