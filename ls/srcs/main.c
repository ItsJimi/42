/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:00:03 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/12 19:09:30 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

int		open_dir(char *str, int sneaky)
{
	DIR				*dir;
	struct dirent	*ent;

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

void	if_exists(char *flags, char c, int *k)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
	{
		if (ft_strchr(flags, c) == NULL)
		{
			flags[*k] = c;
			*k = *k + 1;
		}
	}
	else
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(c);
		ft_putstr("\nusage: ls [-lRart] [file ...]\n");
		exit(-1);
	}
}

void	check_flags(int ac, char **av, char *flags)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
			return ;
		j = 1;
		while (av[i][j])
		{
			if_exists(flags, av[i][j], &k);
			j++;
		}
		i++;
	}
	return ;
}

int		main(int ac, char **av)
{
	int		i;
	char	*flags;

	i = 1;
	flags = ft_strnew(5);
	if (ac > 1)
	{
		check_flags(ac, av, flags);
		ft_putendl(flags);
		/*
			SOON
		*/
	}
	else
	{
		open_dir(".", 0);
	}
	return (0);
}
