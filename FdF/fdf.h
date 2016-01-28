/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:51:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/28 11:24:52 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include <mlx.h>

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

	t_point		***p;

	int			decalx;
	int			decaly;

	int			perspx;
	int			perspy;

	int			space;
	int			dim;

	int			erasing;
	int			pos[5];
}				t_mlx;

t_point			***parse(char *av);
t_point			*new_point(int x, int y, int z);
t_point			***dep_point(t_mlx *mlx, t_point ***p);
int				draw_line(t_mlx *mlx, int pos[5]);
void			draw_point(t_mlx *mlx, t_point ***p);
int				str_exit(int error, char *str);
int				key(int keycode, t_mlx *mlx);

#endif
