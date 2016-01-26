/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 00:54:08 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/17 10:50:23 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base <= 1)
		return (0);
	else if ((base % 2) == 0)
		base /= 2;
	else if ((base % 2) != 0)
		base = base * 3 + 1;
	return (ft_collatz_conjecture(base) + 1);
}
