/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsjimi <itsjimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:00:03 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/20 23:41:03 by itsjimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

void	print_infos(char **av)
{
	t_stat		file_stat;
	t_passwd	*pwd;
	t_group		*grp;

	stat(av[1], &file_stat);
	ft_putstr("\nSize : ");
	ft_putlong(file_stat.st_size);
	ft_putstr("\nBlocks : ");
	ft_putlong(file_stat.st_blocks);
	ft_putstr("\natime : ");
	ft_putlong(file_stat.st_atime);
	ft_putstr("\nnlink : ");
	ft_putlong(file_stat.st_nlink);
	ft_putstr("\nPermissions : ");
	ft_putchar((S_ISFIFO(file_stat.st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(file_stat.st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(file_stat.st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(file_stat.st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(file_stat.st_mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(file_stat.st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(file_stat.st_mode)) ? 's' : '\0');
	ft_putchar((file_stat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((file_stat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((file_stat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((file_stat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((file_stat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((file_stat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((file_stat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((file_stat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((file_stat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("\n\n");
	pwd = getpwuid(file_stat.st_uid);
	ft_putendl(pwd->pw_name);
	grp = getgrgid(file_stat.st_gid);
	ft_putendl(grp->gr_name);
}

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
		ft_lstiter(list, putlst);
		ft_putendl("");
	}
	while (list && ft_strchr(flags, 'R'))
	{
		if (ft_strcmp(list->content, ".") != 0 && ft_strcmp(list->content, "..") != 0)
			power_swag(flags, ft_strjoin(ft_strjoin(path, "/"), list->content));
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
	int		i;
	char	*flags;
	t_list	*args;

	i = 0;
	flags = ft_strnew(7);
	args = NULL;
	if (ac > 1)
	{
		check_args(&args, av, flags);
		while (args)
		{
			power_swag(flags, args->content);
			i++;
			args = args->next;
		}
		if (i == 0)
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
