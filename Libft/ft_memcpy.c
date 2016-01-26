/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:01:46 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/02 18:17:51 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dst);
}
