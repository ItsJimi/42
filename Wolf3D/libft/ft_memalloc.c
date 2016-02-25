/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:11:53 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/03 17:34:42 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zmem;
	char	*tmp;
	size_t	i;

	zmem = (void *)malloc(sizeof(*zmem) * size);
	if (!zmem || size == 0)
		return (NULL);
	i = 0;
	tmp = zmem;
	while (i <= size)
	{
		tmp[i++] = 0;
	}
	return (zmem);
}
