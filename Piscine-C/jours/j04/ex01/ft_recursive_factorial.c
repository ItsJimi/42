/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 13:39:17 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/14 19:57:46 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 2 && nb < 12)
	{
		nb *= ft_recursive_factorial(nb - 1);
		return (nb);
	}
	else if (nb == 2 || nb == 1)
	{
		return (nb);
	}
	else
	{
		return (0);
	}
}
