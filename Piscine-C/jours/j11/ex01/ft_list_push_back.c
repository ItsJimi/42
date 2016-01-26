/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 15:06:03 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/22 18:54:33 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;

	list = *begin_list;
	if (list == NULL)
		list = ft_create_elem(data);
	else
	{
		while (list->next != NULL)
		{
			list->next = ft_create_elem(data);
		}
		list = ft_create_elem(data);
	}
}
