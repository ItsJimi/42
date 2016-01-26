/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 22:52:39 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/11/27 16:07:08 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int	i;
	int	negative;
	int nbr;

	i = 0;
	negative = 1;
	nbr = 0;
	while (str[i] < '0' && str[i] >= '9' && str[i] != '+' && str[i] != '-')
		i++;
	if (str[i] == '-')
		negative = -1;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += ((int)str[i] - 48);
		i++;
	}
	return (nbr * negative);
}
