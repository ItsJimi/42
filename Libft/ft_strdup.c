/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:49:57 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/03 16:56:08 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str1;

	str1 = (char *)malloc(sizeof(*str1) * (ft_strlen(s1) + 1));
	if (str1 == NULL)
		return (NULL);
	ft_strcpy(str1, (char *)s1);
	return (str1);
}
