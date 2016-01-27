/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:27:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/02 14:07:27 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_dtrim(char const *s)
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
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
	{
		i++;
	}
	while (s[i + j])
	{
		tmp[j] = s[i + j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

static	char	*ft_ltrim(char *s)
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
	while (s[len - i] == 32 || s[len - i] == '\n' || s[len - i] == '\t')
	{
		i++;
	}
	len++;
	while (j < len - i)
	{
		tmp[j] = s[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char			*ft_strtrim(char const *s)
{
	if (!s)
		return (NULL);
	if (!ft_ltrim(ft_dtrim(s)))
		return (NULL);
	return (ft_ltrim(ft_dtrim(s)));
}
