/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 22:35:11 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/17 22:40:26 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *p;

	i = 0;
	if (min >= max)
		return (0);
	p = (int*)malloc(sizeof(max - min));
	while (min < max)
	{
		p[i] = min++;
		i++;
	}
	return (p);
}
