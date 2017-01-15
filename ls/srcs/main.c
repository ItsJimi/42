/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsjimi <itsjimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:00:03 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/15 18:06:37 by itsjimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

void	print_infos(char **av)
{
	t_stat		fileStat;
	t_passwd	*pwd;
	t_group		*grp;

	stat(av[1], &fileStat);
    ft_putstr("\nSize : ");
	ft_putlong(fileStat.st_size);
    ft_putstr("\nBlocks : ");
	ft_putlong(fileStat.st_blocks);
	ft_putstr("\natime : ");
	ft_putlong(fileStat.st_atime);
	ft_putstr("\nnlink : ");
	ft_putlong(fileStat.st_nlink);
	ft_putstr("\nPermissions : ");
	ft_putchar((S_ISFIFO(fileStat.st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(fileStat.st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(fileStat.st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(fileStat.st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(fileStat.st_mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(fileStat.st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(fileStat.st_mode)) ? 's' : '\0');
	ft_putchar((fileStat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((fileStat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');

    ft_putstr("\n\n");

    pwd = getpwuid(fileStat.st_uid);
    ft_putendl(pwd->pw_name);

    grp = getgrgid(fileStat.st_gid);
    ft_putendl(grp->gr_name);
}

int		main(int ac, char **av)
{
	int		i;
	char	*flags;

	i = 1;
	flags = ft_strnew(7);
	if (ac > 1)
	{
		check_flags(ac, av, flags);
		ft_putendl(flags);

		// if (ft_strchr(flags, 'R') != -1)
		// {
		// 	ft_putchar('d');
		// }
	}
	else
		open_dir(".", 0);
	return (0);
}