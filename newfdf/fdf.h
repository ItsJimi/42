/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:51:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/27 13:49:47 by jmaiquez         ###   ########.fr       */
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
    int			sizex;
    int			sizey;

    int         px;
    int         py;

    int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

//t_point			***parse(char *av, t_mlx *mlx);
//int				draw(t_mlx *mlx, t_line *line, t_point ***point);
//int				draw2(t_mlx *mlx, t_line *line, t_point ***point);
int				str_exit(int error, char *str);

#endif
