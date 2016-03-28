/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patrick_sebastien.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbollach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 21:49:04 by tbollach          #+#    #+#             */
/*   Updated: 2016/01/07 15:10:49 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	freetab(char **tryresult)
{
	int		i;

	i = 0;
	while (tryresult[i])
	{
		free(tryresult[i]);
		i++;
	}
	free(tryresult);
}

void	place_pattern(char *tab, char **tryresult, int i, int j)
{
	int		h;
	int		l;
	int		m;

	h = 0;
	l = 0;
	m = 0;
	while (ft_isupper(tab[h]) == 0)
		h++;
	while (tab[h + l] != '\0')
	{
		if (tab[h + l] == '\n')
			m++;
		if (ft_isupper(tab[h + l]) == 1)
			tryresult[i + m][j + l - (m * 5)] = tab[h + l];
		l++;
	}
}

void	del_pattern(char **tryresult, int k)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < ft_strlen(tryresult[0]))
	{
		j = 0;
		while (j < ft_strlen(tryresult[0]))
		{
			if (tryresult[i][j] == k + 'A')
				tryresult[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		resolve_son(char **tab, char **tryresult, int *pattern, int x)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < ft_strlen(tryresult[0]))
	{
		j = 0;
		while (j < ft_strlen(tryresult[0]))
		{
			if (check_valid_point(tab[pattern[1]], tryresult, i, j))
			{
				place_pattern(tab[pattern[1]], tryresult, i, j);
				pattern[1]++;
				if (resolve(tab, tryresult, pattern, x))
					return (1);
				pattern[1]--;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		resolve(char **tab, char **tryresult, int *pattern, int x)
{
	if (pattern[0] == pattern[1])
	{
		putabl(tryresult);
		return (1);
	}
	if (resolve_son(tab, tryresult, pattern, x))
		return (1);
	if (pattern[1] != 0)
		del_pattern(tryresult, pattern[1] - 1);
	else if (pattern[1] == 0)
	{
		freetab(tryresult);
		tryresult = holy_result(x + 1);
		pattern[1] = 0;
		if (resolve(tab, tryresult, pattern, x + 1))
			return (1);
		else
			return (0);
	}
	return (0);
}
