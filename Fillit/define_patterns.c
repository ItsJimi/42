/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:42:57 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/07 14:30:28 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nextstep(char **tab, int patterns)
{
	int		i;
	int		j;

	i = 0;
	while (i < patterns)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] != '#' && tab[i][j] != '.' && tab[i][j] != '\n')
				return (1);
			if (tab[i][j] == '\n' && (j != 4 && j != 9 && j != 14))
				return (1);
			if (tab[i][j] == '.' && (j == 4 || j == 9 || j == 14))
				return (1);
			if (tab[i][j] == '#' && (j == 4 || j == 9 || j == 14))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		nextstep2(char **tab, int patterns)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	while (i < patterns)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#' && tab[i][j + 1] == '#')
				k++;
			if (tab[i][j] == '#' && tab[i][j + 5] == '#' && j < 15)
				k++;
			j++;
		}
		if (k < 3)
			return (1);
		j = 0;
		k = 0;
		i++;
	}
	return (0);
}

int		nextstep3(char **tab, int patterns)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < patterns)
	{
		j = 0;
		k = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#')
				k++;
			j++;
		}
		if (k != 4)
			return (1);
		i++;
	}
	return (0);
}

char	**define_tab(char *buf, char **tab, int patterns)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (buf[i] != '\0')
	{
		x = 0;
		if ((tab[y] = (char *)malloc(sizeof(*tab) * 20)) == NULL)
			return (NULL);
		while ((buf[i] != '\n' || buf[i + 1] != '\n') && buf[i] != '\0')
		{
			tab[y][x] = buf[i];
			i++;
			x++;
		}
		if (y == (patterns - 1))
			x--;
		tab[y][x] = '\0';
		y++;
		i += 2;
	}
	return (tab);
}

char	**define_patterns(int patterns, char *buf)
{
	char	**tab;

	if ((tab = (char **)malloc(sizeof(*tab) * patterns + 1)) == NULL)
		return (NULL);
	if ((tab = define_tab(buf, tab, patterns)) == NULL)
		return (NULL);
	tab[patterns] = NULL;
	if (patterns > 26 || patterns <= 0)
		return (NULL);
	if (nextstep(tab, patterns) == 1)
		return (NULL);
	if (nextstep2(tab, patterns) == 1)
		return (NULL);
	if (nextstep3(tab, patterns) == 1)
		return (NULL);
	return (tab);
}
