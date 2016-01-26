/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:31:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/11 16:07:33 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*mem;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	mem = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (mem == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		mem[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		mem[i] = s2[j];
		i++;
		j++;
	}
	mem[i] = '\0';
	return (mem);
}
