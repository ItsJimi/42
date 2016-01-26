/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:39:03 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/04 10:44:45 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 1;
	if (power > 0)
	{
		while (i < power)
		{
			tmp = tmp * nb;
			i++;
		}
		return (tmp);
	}
	else if (power == 0)
		return (1);
	else
		return (0);
}
