/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:51:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/27 19:18:27 by jmaiquez         ###   ########.fr       */
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
t_point			***dep_points(t_mlx *mlx, t_point ***p);
int				draw_line(t_mlx *mlx, int pos[5]);
void			d_points(t_mlx *mlx, t_point ***p);
//int				draw(t_mlx *mlx, t_line *line, t_point ***point);
//int				draw2(t_mlx *mlx, t_line *line, t_point ***point);
int				str_exit(int error, char *str);

#endif
