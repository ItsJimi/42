/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 10:06:13 by malexand          #+#    #+#             */
/*   Updated: 2015/07/30 20:28:30 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

typedef struct	s_dim
{
	int			height;
	int			width;
	int			pos_max_square;
	int			size_max_square;
	int			firstline;
	char		empty_char;
	char		obstacle;
	char		square_char;
}				t_dim;

void			get_size(char *src, t_dim *dimension);
void			replace_square(char *src, t_dim *dim, int width, int position);
t_dim			set_dimension(void);
int				do_operation_map(char *save);
void			ft_putchar(char c);
int				exeption_solver(char *save, t_dim dim);
void			ft_putstr(char *src);
void			ft_putstr2(char *src);
int				open_file(char *input);
int				read_file(int input, char *dest);
int				close_file(int handle);
int				solver(char *src, t_dim *dimension, int position);
int				get_size_max_square(char *src, t_dim *dimension,
									int position, int width);
int				check_array(char *src, t_dim *dimension);
int				close_file(int handle);

#endif
