/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:57:46 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/11/29 14:22:45 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*a;

	if (!lst || !f)
		return (NULL);
	tmp = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (!tmp)
		return (NULL);
	a = tmp;
	lst = lst->next;
	while (lst)
	{
		a->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!a->next)
			return (NULL);
		a = a->next;
		lst = lst->next;
	}
	return (tmp);
}
