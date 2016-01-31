/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:12:44 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/02 11:25:47 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*src2;
	size_t	i;

	str = dest;
	src2 = (char *)src;
	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		str[i] = src2[i];
		i++;
	}
	return (dest);
}
