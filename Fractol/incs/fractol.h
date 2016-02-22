/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:51:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/22 21:02:55 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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

typedef struct	s_line
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			color;
}				t_line;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			av;
	char		*name;

	int			menu;
	int			mouse_on;

	t_img		*img;
	t_line		*line;

	int			h;
	int			w;

	double		movex;
	double		movey;
	double		x;
	double		y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;

	double		zoom;
	int			max;
	int			change_color;

	double		mousex;
	double		mousey;
}				t_mlx;

t_mlx			*new_mlx(t_mlx *mlx, int av, char *name);
t_line			*new_line(int x1, int y1, int x2, int y2);
void			new_window(t_mlx *mlx, char *av);
void			draw(t_mlx *mlx);
void			draw_img(t_mlx *mlx, int i, int x, int y);
int				draw_line(t_mlx *mlx, t_line *line, int color);
void			draw_tree(t_mlx *mlx, t_line *line);
int				mandelbrot(t_mlx *mlx, int x, int y, int i);
int				julia(t_mlx *mlx, int x, int y, int i);
int				burningship(t_mlx *mlx, int x, int y, int i);
int				douady(t_mlx *mlx, int x, int y, int i);
int				key(int keycode, t_mlx *mlx);
int				mouse(int c, int x, int y, t_mlx *mlx);
int				move(int x, int y, t_mlx *mlx);
int				str_exit(int error, char *str);
void			str_data(t_mlx *mlx);
void			zoom_in(int x, int y, t_mlx *mlx);
void			zoom_out(int x, int y, t_mlx *mlx);

#endif
