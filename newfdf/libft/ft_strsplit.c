/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:37:15 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/22 16:28:11 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (word == 0 && str[0] != '\0')
		word++;
	return (word);
}

static	char	**ft_sendword(int i, char **s, const char *str, char c)
{
	int		k;
	int		j;
	int		wrd;

	wrd = ft_count_words(str, c);
	j = 0;
	while (j <= wrd && str[i])
	{
		if (!(s[j] = (char *)malloc(sizeof(s) * ft_strlen(str))))
			return (NULL);
		k = 0;
		while (str[i] != c && str[i])
		{
			s[j][k] = str[i];
			k++;
			i++;
		}
		s[j][k] = '\0';
		while (str[i] == c && str[i] != '\0')
			i += 1;
		j++;
	}
	s[j] = NULL;
	return (s);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	char	**s;

	i = 0;
	if (!(s = (char **)malloc(sizeof(s) * (ft_count_words(str, c) + 1))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	s = ft_sendword(i, s, str, c);
	return (s);
}
