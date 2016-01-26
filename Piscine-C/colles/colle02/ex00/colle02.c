/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 19:02:38 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/26 19:24:45 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

void	extremum_up_2(int x, char *tab, int *k)
{
	int i;

	i = 0;
	tab[*k] = 'A';
	(*k)++;
	while (i++ < x - 2)
	{
		tab[*k] = 'B';
		(*k)++;
	}
	if (x != 1)
	{
		tab[*k] = 'A';
		(*k)++;
	}
	tab[*k] = '\n';
	(*k)++;
}

void	extremum_down_2(int x, char *tab, int *k)
{
	int i;

	i = 0;
	tab[*k] = 'C';
	(*k)++;
	while (i++ < x - 2)
	{
		tab[*k] = 'B';
		(*k)++;
	}
	if (x != 1)
	{
		tab[*k] = 'C';
		(*k)++;
	}
	tab[*k] = '\n';
	(*k)++;
}

void	center_2(int x, int y, char *tab, int *k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < y - 2)
	{
		tab[*k] = 'B';
		(*k)++;
		if (x != 1)
		{
			j = 0;
			while (j++ < x - 2)
			{
				tab[*k] = ' ';
				(*k)++;
			}
			tab[*k] = 'B';
			(*k)++;
		}
		tab[*k] = '\n';
		(*k)++;
		i++;
	}
}

char	*colle_2(int x, int y, char *tab)
{
	int i;
	int k;

	k = 0;
	tab[0] = '\0';
	if (x > 0 && y > 0)
	{
		extremum_up_2(x, tab, &k);
		i = 0;
		center_2(x, y, tab, &k);
		i = 0;
		if (y != 1)
			extremum_down_2(x, tab, &k);
		tab[k] = '\0';
	}
	return (tab);
}

int		pattern_2(int line, int column, char *buf)
{
	int		size;
	char	*tab;

	size = (line + 1) * column + 1;
	tab = malloc(sizeof(char) * size);
	if (ft_strcmp(buf, colle_2(line, column, tab)))
		return (1);
	else
		return (0);
}
