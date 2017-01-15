/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsjimi <itsjimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:36:03 by itsjimi           #+#    #+#             */
/*   Updated: 2017/01/15 18:19:03 by itsjimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

void	putlst(t_list *list)
{
	ft_putendl(list->content);
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
					ft_lstadd(&list, tmp);
				}
			}
		}
		closedir(dir);
		list = ft_lstsort(list);
		ft_lstiter(list, putlst);
		return (1);
	}
	else
	{
		ft_putendl(str);
		return (0);
	}
}