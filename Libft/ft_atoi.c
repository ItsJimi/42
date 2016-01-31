/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:09:46 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/11/28 19:23:56 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *s)
{
	int i;
	int	neg;
	int	result;

	i = 0;
	result = 0;
	neg = 1;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\r' ||
	s[i] == '\v' || s[i] == '\t' || s[i] == '\f')
		i++;
	if (s[i] == '-')
		neg = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			result = result * 10 + s[i] - '0';
		else
			return (result * neg);
		i++;
	}
	result = result * neg;
	return (result);
}
