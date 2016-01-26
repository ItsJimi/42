/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 18:02:22 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/16 19:45:15 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_print_exception(int hour)
{
	if (hour == 11)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		write(1, "11", 2);
		write(1, ".00 A.M. AND ", 13);
		write(1, "12", 2);
		write(1, ".00 P.M.", 8);
	}
	else if (hour == 23)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		write(1, "11", 2);
		write(1, ".00 P.M. AND ", 13);
		write(1, "12", 2);
		write(1, ".00 A.M.", 8);
	}
	else if (hour < 12 && hour != 0 && hour != 11)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		ft_putnbr(hour);
		write(1, ".00 A.M. AND ", 13);
		ft_putnbr(hour + 1);
		write(1, ".00 A.M.", 8);
	}
}

void	ft_print_hour(int hour)
{
	if (hour > 12 && hour < 23)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		ft_putnbr(hour - 12);
		write(1, ".00 P.M. AND ", 13);
		ft_putnbr(hour + 1 - 12);
		write(1, ".00 P.M.", 8);
	}
	else if (hour == 0 || hour == 24)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		write(1, "12", 2);
		write(1, ".00 A.M. AND ", 13);
		write(1, "1", 1);
		write(1, ".00 A.M.", 8);
	}
	else if (hour == 12)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		write(1, "12", 2);
		write(1, ".00 P.M. AND ", 13);
		write(1, "1", 1);
		write(1, ".00 P.M.", 8);
	}
}

void	ft_takes_place(int hour)
{
	ft_print_hour(hour);
	ft_print_exception(hour);
}
