/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 15:09:35 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/10 23:11:17 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_print_comb(void)
{
	int nb1;
	int nb2;
	int nb3;

	nb1 = '/';
	while (nb1 <= '9')
	{
		nb2 = ++nb1;
		while (nb2 <= '9')
		{
			nb3 = ++nb2 + 1;
			while (nb3 <= '9')
			{
				ft_putchar(nb1);
				ft_putchar(nb2);
				ft_putchar(nb3++);
				if (nb1 != '7')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
