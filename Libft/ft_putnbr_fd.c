/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:38:18 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/02 15:52:56 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_putnbr(int n, int j, int started, int fd)
{
	int		i;

	i = 1000000000;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (i != 0)
	{
		if ((n / i) != 0)
		{
			started = 1;
			ft_putchar_fd((n / i) + '0', fd);
			n -= ((n / i) * i);
			j++;
		}
		else if (started)
		{
			ft_putchar_fd('0', fd);
			j++;
		}
		i /= 10;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int		j;

	if (n < 0)
		j = 1;
	else
		j = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
		itoa_putnbr(n, j, 0, fd);
}
