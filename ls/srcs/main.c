/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:00:03 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/23 14:31:36 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

void	power_swag(char *flags, char *path)
{
	t_list	*list;

	list = NULL;
	if (ft_strchr(flags, 'a'))
		list = open_dir(path, 1, 1);
	else
		list = open_dir(path, 0, 1);
	if (list)
	{
		ft_putstr(path);
		ft_putendl(":");
		if (ft_strchr(flags, 'l'))
			ft_lstiter(list, putinfos);
		else
			ft_lstiter(list, putlst);
		ft_putendl("");
	}
	while (list && ft_strchr(flags, 'R'))
	{
		if (ft_strcmp(list->content, ".") != 0 && ft_strcmp(list->content, "..") != 0)
			power_swag(flags, ft_strjoinfree(ft_strjoin(path, "/"), list->content));
		list = list->next;
	}
}

int		is_valid(char *file, t_list **nofile, t_list **nofolder)
{
	t_stat	buffer;

	if (stat(file, &buffer) == -1)
	{
		if (*nofile == NULL)
			*nofile = ft_lstnew(file, (ft_strlen(file) + 1)
				* sizeof(file));
		else
			ft_lstaddend(nofile, ft_lstnew(file, (ft_strlen(file)
				+ 1) * sizeof(file)));
		return (0);
	}
	else
	{
		if (S_ISDIR(buffer.st_mode) == 0)
		{
			if (*nofolder == NULL)
				*nofolder = ft_lstnew(file, (ft_strlen(file) + 1)
					* sizeof(file));
			else
				ft_lstaddend(nofolder, ft_lstnew(file, (ft_strlen(file)
					+ 1) * sizeof(file)));
			return (0);
		}
	}
	return (1);
}

void	check_args(t_list **args, char **av, char *flags)
{
	int		i;
	int		j;
	t_list	*nofile;
	t_list	*nofolder;

	i = check_flags(av, flags);
	j = 0;
	nofile = NULL;
	nofolder = NULL;
	while (av[i])
	{
		if (is_valid(av[i], &nofile, &nofolder))
		{
			if (*args == NULL)
				*args = ft_lstnew(av[i], (ft_strlen(av[i]) + 1)
					* sizeof(av[i]));
			else
				ft_lstaddend(args, ft_lstnew(av[i], (ft_strlen(av[i])
					+ 1) * sizeof(av[i])));
			j++;
		}
		i++;
	}
	*args = ft_lstsort(*args);
	nofile = ft_lstsort(nofile);
	if (j == 0)
		nofolder = ft_lstsort(nofolder);
	ft_lstiter(nofile, putnofile);
	ft_lstiter(nofolder, putlst);
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	char	*flags;
	t_list	*args;

	args = NULL;
	if (ac > 1)
	{
		flags = ft_strnew(7);
		check_args(&args, av, flags);
		while (args)
		{
			power_swag(flags, args->content);
			args = args->next;
		}
		if (!args)
			power_swag(flags, ".");
	}
	else
	{
		t_list	*list;

		list = NULL;
		list = open_dir(".", 0, 1);
		if (list)
			ft_lstiter(list, putlst);
	}
	ft_putstr("\n");
	return (0);
}
