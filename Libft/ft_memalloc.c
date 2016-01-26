/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:45:10 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/11 10:44:32 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	void			*mem;
	unsigned char	*str;

	i = 0;
	mem = (void *)malloc(sizeof(*mem) * size);
	if (mem == NULL)
		return (NULL);
	str = (unsigned char *)mem;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (mem);
}
