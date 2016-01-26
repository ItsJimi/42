/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:40:10 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/11 12:29:30 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*mem;

	i = 0;
	j = 0;
	if ((s == NULL) || ((mem = ft_strnew(ft_strlen(s))) == NULL))
		return (NULL);
	len = ft_strlen(s) - 1;
	while ((s[i] != '\0') && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (i == len + 1)
		return (mem);
	while ((len > 0) && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	len++;
	while (i < len)
	{
		mem[j] = s[i];
		i++;
		j++;
	}
	mem[j] = '\0';
	return (mem);
}
