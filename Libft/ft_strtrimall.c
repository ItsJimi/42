/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:33:28 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/03 16:16:06 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_dtrim(char const *s, char c)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tmp = (char *)malloc(sizeof(*tmp) * (ft_strlen(s) + 1));
	if (tmp == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i + j])
	{
		tmp[j] = s[i + j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

static	char	*ft_ltrim(char *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(*tmp) * (len + 1));
	if (!tmp)
		return (NULL);
	while (s[len - i] == c)
		i++;
	len++;
	while (j < len - i)
	{
		tmp[j] = s[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char			*ft_strtrimall(char const *s, char c)
{
	if (!s)
		return (NULL);
	if (!ft_ltrim(ft_dtrim(s, c), c))
		return (NULL);
	return (ft_ltrim(ft_dtrim(s, c), c));
}
