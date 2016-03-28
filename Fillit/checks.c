/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 13:49:48 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/07 14:52:31 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isupper(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

int		check_valid_point(char *tab, char **tryresult, int i, int j)
{
	int		h;
	int		l;
	int		k;
	int		m;

	h = 0;
	l = 0;
	m = 0;
	while (ft_isupper(tab[h]) == 0 && tab[h] != '\0')
		h++;
	while (tab[h + l] != '\0')
	{
		if (tab[h + l] == '\n')
			m++;
		if (ft_isupper(tab[h + l]) == 1)
		{
			k = j + l - (m * 5);
			if (k < 0 || (i + m) >= (int)ft_strlen(tryresult[0]) ||
					k >= (int)ft_strlen(tryresult[0]) ||
					tryresult[i + m][k] != '.')
				return (0);
		}
		l++;
	}
	return (1);
}

int		check_letter(char **tryresult, int pat)
{
	int		l;
	int		k;

	k = 0;
	l = 0;
	while (k < pat)
	{
		l += check_republic(k, tryresult);
		k++;
	}
	if (l < pat)
		return (1);
	return (0);
}

int		check_republic(int k, char **tryresult)
{
	int		i;
	int		j;

	i = 0;
	while (tryresult[i] != NULL)
	{
		j = 0;
		while (tryresult[i][j] != '\0')
		{
			if (tryresult[i][j] == 'A' + k)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
