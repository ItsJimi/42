/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 13:48:53 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/10 23:09:16 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_print_numbers(void)
{
	int number;

	number = 0;
	while (number <= 9)
	{
		ft_putchar(number + '0');
		number++;
	}
}
