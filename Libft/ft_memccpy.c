/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:01:58 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/07 10:30:55 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	dst2 = (char *)dst;
	src2 = (char *)src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == c)
			return (void *)(&dst[i + 1]);
		i++;
	}
	return (NULL);
}
