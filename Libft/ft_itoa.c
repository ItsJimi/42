/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:46:38 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/03 14:41:29 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*nrm_itoa(int n, int i, int j, int started)
{
	char	*nbr;

	if ((nbr = ft_strnew(11)) == NULL)
		return (NULL);
	if (n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	while (i != 0)
	{
		if ((n / i) != 0)
		{
			started = 1;
			nbr[j] = (n / i) + '0';
			n -= ((n / i) * i);
		}
		else if (started)
			nbr[j] = '0';
		if (((n / i) != 0) || started)
			j++;
		i /= 10;
	}
	return (nbr);
}

static int	n_len(int n)
{
	int		i;
	int		negative;

	i = 0;
	negative = 0;
	if (n < 0)
		negative = 1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i + negative);
}

char		*ft_itoa(int n)
{
	int		j;
	char	*s;

	s = (char*)malloc(sizeof(*s) * n_len(n));
	if (s == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strcpy(s, "0"));
	if (n < 0)
		j = 1;
	else
		j = 0;
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	s = nrm_itoa(n, 1000000000, j, 0);
	return (s);
}
