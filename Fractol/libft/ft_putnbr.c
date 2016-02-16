/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:54:57 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/04 10:57:54 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_val(int n)
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

void		ft_putnbr(int n)
{
	int	j;
	int	i;
	int	power;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	i = 0;
	j = 0;
	if (n < 0)
	{
		ft_putchar('-');
		i++;
		n = n * (-1);
	}
	while (j < ft_val(n))
	{
		power = ft_val(n) - j - 1;
		ft_putchar(48 + (n / (ft_power(10, power)) % 10));
		j++;
	}
}
