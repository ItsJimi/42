/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 13:00:13 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/23 15:32:18 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#define BUF_SIZE 4096

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (argc < 2)
		write(2, "File name missing.\n", 20);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 21);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(2, "open() error", 12);
			return (1);
		}
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		write(1, buf, ret);
		if (close(fd) == -1)
		{
			write(2, "close() error", 13);
			return (1);
		}
	}
}
