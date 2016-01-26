/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 09:25:51 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/14 19:56:12 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int lim;

	i = 1;
	lim = nb;
	if (nb < 0)
	{
		return (0);
	}
	else
	{
		while (i < lim)
		{
			nb *= i;
			i++;
		}
		return (nb);
	}
}
