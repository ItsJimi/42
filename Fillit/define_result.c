/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbollach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:12:33 by tbollach          #+#    #+#             */
/*   Updated: 2016/01/07 15:08:25 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	putabl(char **tabl)
{
	int		i;

	i = 0;
	while (tabl[i] != NULL)
	{
		ft_putstr(tabl[i]);
		ft_putchar('\n');
		i++;
	}
}

void	holy_letter(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#')
				tab[i][j] = 'A' + i;
			j++;
		}
		i++;
	}
}

void	holy_point(char *tryresult, int x)
{
	int		i;

	i = 0;
	while (i < x)
	{
		tryresult[i] = '.';
		i++;
	}
	tryresult[i] = '\0';
}

char	**holy_result(int x)
{
	char	**tryresult;
	int		i;

	i = 0;
	if ((tryresult = (char**)malloc(sizeof(char*) * x + 1)) == NULL)
		return (NULL);
	while (i < x)
	{
		if ((tryresult[i] = (char*)malloc(sizeof(char) * x + 1)) == NULL)
			return (NULL);
		holy_point(tryresult[i], x);
		i++;
	}
	tryresult[x] = NULL;
	return (tryresult);
}

void	holy_resolve(char **tab, int pat)
{
	int		i;
	int		x;
	char	**tryresult;
	int		pattern[2];

	pattern[0] = pat;
	pattern[1] = 0;
	x = 0;
	i = pat * 4;
	holy_letter(tab);
	while ((x * x) < i)
		x++;
	while ((tryresult = holy_result(x)) == NULL)
		x++;
	resolve(tab, tryresult, pattern, x);
	if (tryresult == NULL)
		return ;
}
