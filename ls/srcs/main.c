/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsjimi <itsjimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:00:03 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/15 16:36:56 by itsjimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

int		main(int ac, char **av)
{
	int		i;
	char	*flags;
	t_stat 	fileStat;
	struct passwd *pwd;
	struct group *grp;

	i = 1;
	flags = ft_strnew(6);
	if (ac > 1)
	{
		check_flags(ac, av, flags);
		ft_putendl(flags);
		if(stat(av[1], &fileStat) < 0)
        	return 1;
        ft_putstr("\nSize : ");
		ft_putlong(fileStat.st_size);
        ft_putstr("\nBlocks : ");
		ft_putlong(fileStat.st_blocks);
		ft_putstr("\natime : ");
		ft_putlong(fileStat.st_atime);
		ft_putstr("\nnlink : ");
		ft_putlong(fileStat.st_nlink);
		ft_putstr("\nPermissions : ");
		ft_putstr((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	    ft_putstr((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	    ft_putstr((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	    ft_putstr((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	    ft_putstr((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	    ft_putstr((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	    ft_putstr((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	    ft_putstr((fileStat.st_mode & S_IROTH) ? "r" : "-");
	    ft_putstr((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	    ft_putstr((fileStat.st_mode & S_IXOTH) ? "x" : "-");

	    ft_putstr("\n\n");

	    pwd = getpwuid(fileStat.st_uid);
	    ft_putendl(pwd->pw_name);

	    grp = getgrgid(fileStat.st_gid);
	    ft_putendl(grp->gr_name);
	}
	else
	{
		open_dir(".", 0);
	}
	return (0);
}