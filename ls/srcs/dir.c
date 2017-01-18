/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:36:03 by itsjimi           #+#    #+#             */
/*   Updated: 2017/01/18 18:24:36 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

static void	read_dir(t_list **list, DIR **dir, int sneaky, int sort)
{
	t_dirent	*ent;
	t_list		*tmp;

	tmp = NULL;
	while ((ent = readdir(*dir)) != NULL)
	{
		if (ent->d_name[0] != '.' || sneaky == 1)
		{
			if (*list == NULL)
				*list = ft_lstnew(ent->d_name, (ft_strlen(ent->d_name) + 1)
					* sizeof(ent->d_name));
			else
			{
				tmp = ft_lstnew(ent->d_name, (ft_strlen(ent->d_name)
					+ 1) * sizeof(ent->d_name));
				ft_lstaddend(list, tmp);
			}
		}
	}
	if (sort == 1)
		*list = ft_lstsort(*list);
	else if (sort == -1)
		*list = ft_lstsortrev(*list);
}

t_list		*open_dir(char *str, int sneaky, int sort)
{
	DIR		*dir;
	t_list	*list;

	list = NULL;
	if ((dir = opendir(str)) != NULL)
	{
		read_dir(&list, &dir, sneaky, sort);
		closedir(dir);
	}
	return (list);
}
