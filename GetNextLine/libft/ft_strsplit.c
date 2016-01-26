/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:19:12 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/01 19:14:48 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_cleanstr(const char *str, char c)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	j = 0;
	if (!str || !c)
		return (NULL);
	s = (char *)malloc(sizeof(*s) * ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	while (str[i] == c)
		i++;
	while (str[i])
	{
		s[j] = str[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}

static	char	*ft_cleanstrend(const char *str, char c)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	j = 0;
	if (!str || !c)
		return (NULL);
	s = (char *)malloc(sizeof(*s) * ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	while (str[ft_strlen(str) - i - 1] == c)
		i++;
	while (j < ft_strlen(str) - i)
	{
		s[j] = str[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

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
	return (word);
}

static	char	**ft_dotab(char *tmp, char **s, char c)
{
	int	j;
	int	w;
	int	i;

	i = 0;
	w = 0;
	while (w <= ft_count_words(tmp, c))
	{
		j = 0;
		s[w] = (char *)malloc(sizeof(s[w]) * ft_strlen(tmp) + 1);
		if (!s[w])
			return (NULL);
		while (tmp[i] != c && tmp[i] != '\0')
			s[w][j++] = tmp[i++];
		s[w][j] = '\0';
		while (tmp[i] == c)
			i++;
		w++;
	}
	s[w] = 0;
	return (s);
}

char			**ft_strsplit(char const *str, char c)
{
	char	*tmp;
	char	**s;

	s = (char **)malloc(sizeof(**s) * ft_count_words(str, c) + 1);
	if (!s)
	{
		s[0] = NULL;
		return (s);
	}
	s[0] = NULL;
	if (!str || !c)
		return (s);
	tmp = (char *)malloc(sizeof(*tmp) * ft_strlen(str) + 1);
	if (!tmp)
		return (s);
	tmp = ft_cleanstrend(ft_cleanstr(str, c), c);
	if (tmp[0] == '\0')
		return (s);
	s = ft_dotab(tmp, s, c);
	free(tmp);
	tmp = NULL;
	return (s);
}
