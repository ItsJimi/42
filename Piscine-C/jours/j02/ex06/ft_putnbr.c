/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 23:38:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/10 23:23:13 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
	int i;
	int nb;

	i = 0;
	nb = nbr;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	

}

int main()
{
	ft_putnbr(42);
}
