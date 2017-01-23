/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:50:27 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/23 16:51:05 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

void		putlst(t_list *list)
{
	ft_putstr(list->content);
	ft_putstr(" ");
}

void		putnofile(t_list *list)
{
	ft_putstr("ls: ");
	ft_putstr(list->content);
	ft_putendl(": No such file or directory");
}

void		putinfos(t_list *list)
{
	t_stat		file_stat;
	t_passwd	*pwd;
	t_group		*grp;
	int			i;
	char		**name;

	i = 0;
	stat(list->content, &file_stat);
	ft_putlong(file_stat.st_blocks);
	ft_putstr(" ");
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
	ft_putstr(" ");
	ft_putlong(file_stat.st_nlink);
	ft_putstr(" ");
	pwd = getpwuid(file_stat.st_uid);
	ft_putstr(pwd->pw_name);
	ft_putstr(" ");
	grp = getgrgid(file_stat.st_gid);
	ft_putstr(grp->gr_name);
	ft_putstr(" ");
	ft_putlong(file_stat.st_size);
	ft_putstr(" ");
	ft_putlong(file_stat.st_atime);
	ft_putstr(" ");
	name = ft_strsplit(list->content, '/');
	while (name[i])
		i++;
	ft_putstr(name[i - 1]);
	ft_putstr("\n");
	ft_freedtab(name);
}