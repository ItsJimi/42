/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:08:36 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/11/30 12:15:23 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		negative;
	int		nbr;
	int		i;
	int		j;

	negative = 1;
	nbr = 0;
	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i + j] == '-' || str[i + j] == '+')
		j++;
	if (str[i] == '-')
		negative = -1;
	while (str[j + i] >= '0' && str[j + i] <= '9')
	{
		nbr *= 10;
		nbr += ((int)str[j + i]) - '0';
		i++;
	}
	if (j > 1)
		return (0);
	return (nbr * negative);
}
