/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:31:08 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/11 12:27:15 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = (char *)malloc(sizeof(*mem) * size + 1);
	if (mem == NULL)
		return (NULL);
	while (i < (size + 1))
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
