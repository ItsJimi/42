/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:00:03 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/10 17:33:13 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		open_dir(char *str, int sneaky)
{
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(str)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			if ((ft_strcmp(ent->d_name, ".") != 0
				&& ft_strcmp(ent->d_name, "..") != 0) || sneaky == 1)
			{
				ft_putstr(ent->d_name);
				ft_putchar('\n');
			}
		}
		closedir(dir);
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*check_flags(int ac, char **av)
{
	int		i;
	int		j;
	char	*flags;

	i = 1;
	flags = ft_strnew(5);
	while (i < ac)
	{
		if (av[i][0] != '-')
			return (flags);
		j = 0;
		while (av[i][j])
		{
			ft_putchar(av[i][j]);
			flags[j] = av[i][j];
			j++;
		}
		i++;
	}
	return (flags);
}

int		main(int ac, char **av)
{
	int		i;
	//char	*error;

	i = 1;
	if (ac > 1)
	{
		ft_putstr(check_flags(ac, av));
		// while (i < ac)
		// {
		// 	if (av[i][0] == '-')
		// 	{
		// 		if (0)
		// 		{
		// 			if (ft_strchr(av[i], 'l') != NULL)
		// 			{
		// 				ft_putstr("l");
		// 			}
		// 			if (ft_strchr(av[i], 'R') != NULL)
		// 			{
		// 				ft_putstr("R");
		// 			}
		// 			if (ft_strchr(av[i], 'a') != NULL)
		// 			{
		// 				ft_putstr("a");
		// 			}
		// 			if (ft_strchr(av[i], 'r') != NULL)
		// 			{
		// 				ft_putstr("r");
		// 			}
		// 			if (ft_strchr(av[i], 't') != NULL)
		// 			{
		// 				ft_putstr("t");
		// 			}
		// 		}
		// 		else
		// 		{
		// 			if (!(error = (char *)malloc(sizeof(*error)
		// 			* ft_strlen(av[1]))))
		// 			{
		// 				ft_putstr("malloc error");
		// 				return (0);
		// 		 	}
		// 			error = ft_strsplit(av[1], '-')[1];
		// 			ft_putstr("ls: illegal option ");
		// 			ft_putstr(error);
		// 		}
		// 	}
		// 	else
		// 	{
		// 		if (ac > 2)
		// 		{
		// 			ft_putstr(av[i]);
		// 			ft_putstr(":\n");
		// 		}
		// 		open_dir(av[i], 0);
		// 	}
		// 	i++;
		// 	if (i != ac)
		// 		ft_putchar('\n');
		// }
	}
	else
	{
		open_dir(".", 0);
		struct passwd *pwd;
		struct stat statbuf;

		pwd = getpwuid(statbuf.st_uid);
		ft_putstr(statbuf.st_uid);
	}
	return (0);
}
