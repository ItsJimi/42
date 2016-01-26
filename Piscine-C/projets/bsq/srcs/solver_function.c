/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 19:47:13 by malexand          #+#    #+#             */
/*   Updated: 2015/07/30 20:26:58 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_dim	set_dimension(void)
{
	t_dim dim;

	dim.height = 0;
	dim.width = 0;
	dim.pos_max_square = 0;
	dim.firstline = 0;
	dim.size_max_square = 0;
	return (dim);
}

int		do_operation_map(char *save)
{
	t_dim dim;

	dim = set_dimension();
	if (check_array(save, &dim) == -1)
	{
		ft_putstr("map error\n");
		return (-1);
	}
	get_size(save, &dim);
	if (dim.width < 2 || dim.height < 2)
	{
		if (exeption_solver(save, dim) == 0)
			return (-1);
	}
	solver(save, &dim, (dim.width * dim.height + dim.height + dim.firstline));
	replace_square(save, &dim, dim.size_max_square, dim.pos_max_square);
	ft_putstr2(save);
	return (1);
}

int		exeption_solver(char *save, t_dim dim)
{
	int i;

	i = 0;
	if (dim.width == 1 || dim.height == 1)
	{
		while (save[i] != '\0')
		{
			if (save[dim.firstline + i] == dim.empty_char)
			{
				save[dim.firstline + i] = dim.square_char;
				return (1);
			}
			i++;
		}
	}
	if (dim.width == 0 || dim.height == 0)
	{
		ft_putstr("map error\n");
		return (0);
	}
	return (1);
}
