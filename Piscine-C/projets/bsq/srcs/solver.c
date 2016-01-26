/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 13:10:36 by malexand          #+#    #+#             */
/*   Updated: 2015/07/30 20:04:46 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		check_array(char *src, t_dim *dimension)
{
	int		nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (src[nbr] != '\n')
		nbr++;
	dimension->square_char = src[nbr - 1];
	dimension->obstacle = src[nbr - 2];
	dimension->empty_char = src[nbr - 3];
	dimension->firstline = nbr;
	i = nbr + 1;
	while (src[i] != '\0')
	{
		if (src[i] != dimension->empty_char && src[i] != dimension->obstacle
				&& src[i] != '\n')
			return (-1);
		i++;
	}
	return (1);
}

void	replace_square(char *src, t_dim *dim, int width, int position)
{
	int		tmp;
	int		height;
	int		tmp1;
	char	tmp2;
	char	tmp3;

	tmp1 = dim->width;
	tmp2 = dim->square_char;
	tmp3 = dim->empty_char;
	height = width - 1;
	tmp = width;
	while (height > 0)
	{
		width = tmp;
		while (width > 1)
		{
			if (src[position - ((tmp1 + 1) * height) - (width + 1)] == tmp3)
			{
				src[position - ((tmp1 + 1) * height) - (width + 1)] = tmp2;
			}
			width--;
		}
		height--;
	}
}

void	get_size(char *src, t_dim *dimension)
{
	int		i;

	i = 0;
	dimension->width = 0;
	dimension->height = 0;
	while (src[i] != '\n')
		i++;
	i++;
	while (src[i] != '\0')
	{
		while (src[i] != '\n' && dimension->height == 0)
		{
			dimension->width++;
			i++;
		}
		if (src[i] == '\n')
			dimension->height++;
		i++;
		dimension->firstline = 5;
	}
}

int		get_size_max_square(char *src, t_dim *dim, int position, int width)
{
	int		tmp;
	int		height;
	int		tmp1;
	char	tmp2;

	tmp1 = dim->width;
	tmp2 = dim->empty_char;
	height = width - 1;
	tmp = width;
	while (height > 0)
	{
		width = tmp;
		while (width > 1)
		{
			if (src[position - ((tmp1 + 1) * height) - (width + 1)] != tmp2)
				return (-1);
			width--;
		}
		height--;
	}
	return (1);
}

int		solver(char *src, t_dim *dimension, int position)
{
	int		nb;

	dimension->firstline = 5;
	nb = 1;
	while (position > dimension->firstline + 1)
	{
		if (src[position] == dimension->empty_char)
		{
			while (get_size_max_square(src, dimension, position, nb) > 0)
			{
				nb++;
			}
			if (dimension->size_max_square <= (nb - 1))
			{
				dimension->size_max_square = nb - 1;
				dimension->pos_max_square = position;
			}
		}
		nb = 0;
		position--;
	}
	return (0);
}
