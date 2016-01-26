/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:51:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/26 20:21:09 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SPACE 10
# define AAA 4

# include "libft/includes/libft.h"
# include <mlx.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_line;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			sizex;
	int			sizey;
}				t_mlx;

t_point			***parse(t_mlx *mlx, int fd);
int				draw(t_mlx *mlx, t_line *line, t_point ***point);
int				draw2(t_mlx *mlx, t_line *line, t_point ***point);
int				error(char *str);
void	put_points(t_point ***points);

#endif
