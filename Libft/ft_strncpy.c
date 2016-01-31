/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:15:09 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/05 18:11:26 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n && src[k])
	{
		dst[k] = src[k];
		k++;
	}
	while (k != n)
	{
		dst[k] = '\0';
		k++;
	}
	return (dst);
}
