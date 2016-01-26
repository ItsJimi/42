/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:22:54 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/11 12:24:52 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*mem;

	i = (size_t)start;
	j = 0;
	mem = (char *)malloc(sizeof(*mem) * len + 1);
	if (mem == NULL || s == NULL)
		return (NULL);
	while (i < (start + len))
	{
		mem[j] = s[i];
		j++;
		i++;
	}
	mem[j] = '\0';
	return (mem);
}
