/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:00:28 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/02 10:42:02 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	if (ft_strlen(s2) < n)
		len = ft_strlen(s2);
	else
		len = n;
	if (len < ft_strlen(s2))
		return (NULL);
	i = 0;
	while (s1[i] && len + i < n + 1)
	{
		if (ft_strncmp(&s1[i], s2, len) == 0)
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
