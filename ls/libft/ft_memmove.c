/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:44:37 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/11/28 18:35:12 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*tmp;
	char	*src2;
	size_t	i;

	tmp = (char *)malloc(sizeof(tmp) * len);
	dst2 = dst;
	src2 = (char *)src;
	i = 0;
	if (len == 0 || dst2 == src2)
		return (dst2);
	while (i < len)
	{
		tmp[i] = src2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst2[i] = tmp[i];
		i++;
	}
	free(tmp);
	tmp = NULL;
	return (dst);
}
