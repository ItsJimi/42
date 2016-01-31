/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:43:49 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/01 18:10:27 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*lch;

	i = 0;
	lch = NULL;
	while (s[i])
	{
		if (s[i] == c)
			lch = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char*)&s[i]);
	return (lch);
}
