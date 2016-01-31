/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:49:51 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/11/28 19:03:26 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)s;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == ch)
		{
			return (void *)(&s[i]);
		}
		i++;
	}
	return (NULL);
}
