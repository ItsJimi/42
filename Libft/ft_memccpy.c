/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:25:00 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/11 11:13:28 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*dest;

	i = 0;
	str = (unsigned char *)src;
	dest = dst;
	if (n == 0)
		return (NULL);
	while (i < n && str[i] != (unsigned char)c)
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == (unsigned char)c && i != n)
	{
		dest[i] = str[i];
		return (&dst[i + 1]);
	}
	return (NULL);
}
