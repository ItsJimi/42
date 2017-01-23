/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:16:00 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/23 13:25:56 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *str1, char const *str2)
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
		free(str1);
		return (newstr);
	}
	return (NULL);
}
