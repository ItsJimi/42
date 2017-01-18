/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortrev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:59:59 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/18 19:06:42 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsortrev(t_list *list)
{
	t_list		*tmplist;
	t_list		*save;
	char		*tmp;

	save = list;
	while (list)
	{
		tmplist = list;
		while (tmplist)
		{
			if (ft_strcmp(list->content, tmplist->content) < 0)
			{
				tmp = list->content;
				list->content = tmplist->content;
				tmplist->content = tmp;
				ft_swap(&list->content_size, &tmplist->content_size);
			}
			tmplist = tmplist->next;
		}
		list = list->next;
	}
	return (save);
}
