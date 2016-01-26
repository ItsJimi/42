/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:28:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/10 14:22:29 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_putnbr(int n, int i, int j, int started)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	while (i != 0)
	{
		if ((n / i) != 0)
		{
			started = 1;
			ft_putchar((n / i) + '0');
			n -= ((n / i) * i);
			j++;
		}
		else if (started)
		{
			ft_putchar('0');
			j++;
		}
		i /= 10;
	}
}

void		ft_putnbr(int n)
{
	int		j;

	if (n < 0)
		j = 1;
	else
		j = 0;
	if (n == 0)
		ft_putchar('0');
	else if (n == -2147483648)
		ft_putstr("-2147483648");
	else
		itoa_putnbr(n, 1000000000, j, 0);
}
