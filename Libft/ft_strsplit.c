/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:45:26 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/11 16:13:19 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (!s || !c)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			words++;
		}
	}
	return (words);
}

static char	**init_tab(size_t n)
{
	char			**tab;
	unsigned int	i;

	if (!n)
		return ((char**)NULL);
	i = 0;
	if ((tab = (char**)malloc(sizeof(**tab) * n)) == NULL)
		return (NULL);
	while (i != n)
	{
		tab[i] = malloc(sizeof(NULL));
		tab[i] = NULL;
		i++;
	}
	return (tab);
}

char		**ft_strsplit(const char *s, char c)
{
	int		start;
	int		len;
	size_t	words;
	size_t	n;
	char	**tab;

	start = 0;
	n = 0;
	words = count_words(s, c);
	if ((tab = init_tab(words + 1)) == NULL)
		return (NULL);
	while (n < words)
	{
		len = 0;
		while (s[start] == c)
			start++;
		start--;
		while (s[++start] != c && s[start] != '\0')
			len++;
		tab[n] = ft_strsub(s, start - len, len);
		n++;
	}
	tab[n] = NULL;
	return (tab);
}
