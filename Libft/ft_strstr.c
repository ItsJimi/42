/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:42:22 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/11/27 17:46:10 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int			i;
	size_t		j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return (char *)(s1);
	while (s1[i])
	{
		while (s1[i] != s2[0])
		{
			i++;
			if (s1[i] == '\0')
				return (NULL);
		}
		while (s1[i + j] == s2[j] && s2[j] != '\0')
		{
			j++;
		}
		if (j == ft_strlen(s2))
			return (char *)(&s1[i]);
		i++;
	}
	return (NULL);
}
