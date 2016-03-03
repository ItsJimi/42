/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:51:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/03 20:47:39 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

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

	int			beginx;
	int			beginy;

	t_point		***p;
	t_img		*img;

	int			menu;
}				t_mlx;

void			dep(t_mlx *mlx, t_point ***p);
t_point			***parse(char *av, t_mlx *mlx);
t_point			*new_point(int x, int y, char *z, t_mlx *mlx);
t_mlx			*new_mlx(t_mlx *mlx, char *av);
t_img			*new_img(t_mlx *mlx);
void			draw(t_mlx *mlx);
int				str_exit(int error, char *str);
int				key(int keycode, t_mlx *mlx);
void			str_data(t_mlx *mlx);
int				gnl_error(char *tab);

#endif
