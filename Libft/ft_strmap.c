/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:16:18 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/03 17:06:44 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*mem;

	if (s != NULL && f != NULL)
	{
		i = 0;
		mem = ft_strnew(ft_strlen(s));
		if (mem == NULL)
			return (NULL);
		ft_strcpy(mem, (char *)s);
		while (s[i] != '\0')
		{
			mem[i] = f(s[i]);
			i++;
		}
		return (mem);
	}
	return (NULL);
}
