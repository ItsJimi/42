/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 20:26:07 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/11 22:51:28 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	swap;

	i = 0;
	size = 0;
	while (str[size])
	{
		size++;
	}
	size = size - 1;
	while (i < size)
	{
		swap = str[size];
		str[size] = str[i];
		str[i] = swap;
		i++;
		size--;
	}
	return (str);
}
