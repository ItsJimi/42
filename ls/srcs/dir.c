/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:36:03 by itsjimi           #+#    #+#             */
/*   Updated: 2017/01/16 18:34:43 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

void	putlst(t_list *list)
{
	ft_putstr(list->content);
	ft_putstr("  ");
}

t_list	*ft_lstsort(t_list *list)
{
	t_list		*tmp;
	t_list		*tmpm;
	t_list		*new;
	int			index;

	tmp = list;
	new = NULL;
	index = 0;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->content, tmp->next->content) < 0)
		{

		}
		index++;
	}
	return (new);
}

int		open_dir(char *str, int sneaky)
{
	DIR				*dir;
	t_dirent		*ent;
	t_list			*list;
	t_list			*tmp;

	list = NULL;
	tmp = NULL;
	if ((dir = opendir(str)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			if (ent->d_name[0] != '.' || sneaky == 1)
			{
				if (list == NULL)
				{
					list = ft_lstnew(ent->d_name, (ft_strlen(ent->d_name) + 1)
						* sizeof(ent->d_name));
				}
				else
				{
					tmp = ft_lstnew(ent->d_name, (ft_strlen(ent->d_name)
						+ 1) * sizeof(ent->d_name));
					ft_lstaddend(&list, tmp);
				}
			}
		}
		closedir(dir);
		//list = ft_lstsort(list);
		ft_lstiter(list, putlst);
		return (1);
	}
	else
	{
		ft_putendl(str);
		return (0);
	}
}