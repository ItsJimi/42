/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 19:02:38 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/26 19:23:12 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

void	extremum_up_0(int x, char *tab, int *k)
{
	int i;

	i = 0;
	tab[*k] = 'o';
	(*k)++;
	while (i++ < x - 2)
	{
		tab[*k] = '-';
		(*k)++;
	}
	if (x != 1)
	{
		tab[*k] = 'o';
		(*k)++;
	}
	tab[*k] = '\n';
	(*k)++;
}

void	extremum_down_0(int x, char *tab, int *k)
{
	int i;

	i = 0;
	tab[*k] = 'o';
	(*k)++;
	while (i++ < x - 2)
	{
		tab[*k] = '-';
		(*k)++;
	}
	if (x != 1)
	{
		tab[*k] = 'o';
		(*k)++;
	}
	tab[*k] = '\n';
	(*k)++;
}

void	center_0(int x, int y, char *tab, int *k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < y - 2)
	{
		tab[*k] = '|';
		(*k)++;
		if (x != 1)
		{
			j = 0;
			while (j++ < x - 2)
			{
				tab[*k] = ' ';
				(*k)++;
			}
			tab[*k] = '|';
			(*k)++;
		}
		tab[*k] = '\n';
		(*k)++;
		i++;
	}
}

char	*colle_0(int x, int y, char *tab)
{
	int i;
	int k;

	k = 0;
	tab[0] = '\0';
	if (x > 0 && y > 0)
	{
		extremum_up_0(x, tab, &k);
		i = 0;
		center_0(x, y, tab, &k);
		i = 0;
		if (y != 1)
			extremum_down_0(x, tab, &k);
		tab[k] = '\0';
	}
	return (tab);
}

int		pattern_0(int line, int column, char *buf)
{
	int		size;
	char	*tab;

	size = (line + 1) * column + 1;
	tab = malloc(sizeof(char) * size);
	if (ft_strcmp(buf, colle_0(line, column, tab)))
		return (1);
	else
		return (0);
}
