/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:16:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/11 12:09:42 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*mem;

	i = 0;
	if (s != NULL || f != NULL)
	{
		len = ft_strlen(s);
		mem = ft_strnew(len);
		if (mem == NULL)
			return (NULL);
		ft_strcpy(mem, (char *)s);
		while (s[i] != '\0')
		{
			mem[i] = f(i, s[i]);
			i++;
		}
		return (mem);
	}
	return (NULL);
}
