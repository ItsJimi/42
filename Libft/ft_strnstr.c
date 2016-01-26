/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:56:39 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/02 15:07:24 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		while (i < n && (s1[i] == s2[j] || s2[j] == '\0'))
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i - j]);
		}
		i++;
	}
	return (NULL);
}
