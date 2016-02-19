/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:51:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/02/18 16:50:56 by jmaiquez         ###   ########.fr       */
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

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	char		*av;

	t_img		*img;

	int			h;
	int			w;

	double		x;
	double		y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;

	int			zoom;
	int			max;
}				t_mlx;

void	draw(t_mlx *mlx);
int		str_exit(int error, char *str);
t_mlx	*new_mlx(t_mlx *mlx, char *av);
int		key(int keycode, t_mlx *mlx);
int		mouse(int c, int x, int y, t_mlx *mlx);

#endif
