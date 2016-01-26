/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 23:31:08 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/26 23:32:23 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

void	putcolle(int line, int column, char *tcolle, int i)
{
	ft_putstr("[colle-0");
	ft_putchar(tcolle[i]);
	ft_putstr("] ");
	ft_putstr("[");
	ft_putnbr(line);
	ft_putstr("] ");
	ft_putchar('[');
	ft_putnbr(column);
	ft_putchar(']');
}

void	put(int line, char *tcolle, int size, int column)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (size == 0)
		ft_putstr("aucune");
	while (count < size)
	{
		putcolle(line, column, tcolle, i);
		if (size > 1 && count != size - 1)
			ft_putstr(" || ");
		count++;
		i++;
	}
	ft_putchar('\n');
}
