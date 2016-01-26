/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 18:14:30 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/21 19:08:36 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *stock;

	i = 0;
	stock = (int*)malloc(sizeof(int) * length);
	while (i < length)
	{
		stock[i] = f(tab[i]);
		i++;
	}
	return (*tab);
}
