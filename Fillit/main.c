/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:39:57 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/08 17:10:29 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUF_SIZE 554

int		closefd(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int		openfd(char const *argv)
{
	int		fd;

	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (fd);
	}
	return (fd);
}

int		calcargc(int argc)
{
	if (argc != 2)
		ft_putstr("error\n");
	return (argc);
}

int		patterns_error(int ret)
{
	if (((ret + 1) % 21) != 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**tab;

	if (calcargc(argc) != 2)
		return (0);
	if ((fd = openfd(argv[1])) == -1)
		return (0);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (patterns_error(ret) != 0)
		return (0);
	if (closefd(fd) == -1)
		return (0);
	if ((tab = define_patterns((ret + 1) / 21, buf)) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	holy_resolve(tab, (ret + 1) / 21);
	return (0);
}
