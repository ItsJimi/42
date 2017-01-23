/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:36:03 by itsjimi           #+#    #+#             */
/*   Updated: 2017/01/23 16:33:31 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

static void	read_dir(t_list **list, DIR **dir, int sneaky, char *path)
{
	t_dirent	*ent;
	t_list		*tmp;

	tmp = NULL;
	while ((ent = readdir(*dir)) != NULL)
	{
		if (ent->d_name[0] != '.' || sneaky == 1)
		{
			if (*list == NULL)
				*list = ft_lstnew(ft_strjoin(ft_strjoin(path, "/"), ent->d_name), (ft_strlen(ent->d_name) + 1)
					* sizeof(ent->d_name));
			else
				ft_lstaddend(list, ft_lstnew(ft_strjoin(ft_strjoin(path, "/"), ent->d_name), (ft_strlen(ent->d_name)
					+ 1) * sizeof(ent->d_name)));
		}
	}
	free(ent);
}

t_list		*open_dir(char *path, int sneaky, int sort)
{
	DIR		*dir;
	t_list	*list;

	list = NULL;
	if ((dir = opendir(path)) != NULL)
	{
		read_dir(&list, &dir, sneaky, path);
		closedir(dir);
	}
	if (sort == 1)
		list = ft_lstsort(list);
	else if (sort == -1)
		list = ft_lstsortrev(list);
	return (list);
}
