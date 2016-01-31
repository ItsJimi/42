/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:36:05 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/12/03 15:38:16 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freedtab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
	{
		free(tab);
		tab = NULL;
		return ;
	}
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab[i]);
	tab[i] = NULL;
	free(tab);
	tab = NULL;
}
