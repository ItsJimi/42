/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:30:22 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/14 14:28:38 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*newstr;
	int		i;
	int		j;

	if (str1 && str2)
	{
		newstr = (char *)malloc(sizeof(newstr) *
								(ft_strlen(str1) + ft_strlen(str2) + 1));
		if (newstr == NULL)
			return (NULL);
		i = -1;
		while (str1[++i])
			newstr[i] = str1[i];
		j = -1;
		while (str2[++j])
			newstr[i + j] = str2[j];
		newstr[i + j] = '\0';
		return (newstr);
	}
	return (NULL);
}
