/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:52:46 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/04 10:57:35 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_val(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*tab;
	int		power;

	i = 0;
	j = 0;
	tab = (char*)malloc(sizeof(*tab) * (ft_val(n) + 1));
	if (!tab)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(tab, "-2147483648"));
	if (n < 0)
	{
		tab[0] = '-';
		i++;
		n = n * (-1);
	}
	while (j < ft_val(n))
	{
		power = ft_val(n) - (j++) - 1;
		tab[i++] = 48 + (n / (ft_power(10, power)) % 10);
	}
	tab[i] = '\0';
	return (tab);
}
