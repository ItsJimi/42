/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 17:52:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/14 19:58:16 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int	nbr;

	i = 0;
	nbr = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (0);
	if (power == 1)
		return (nb);
	if (power < 1)
	{
		while (i < power)
		{
			nbr *= nb;
			i++;
		}
		return (nbr);
	}
	else
		return (0);
}
