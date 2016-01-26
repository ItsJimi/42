/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 14:17:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/25 19:40:52 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#define BUF_SIZE 3000

void	count_columns(char *buf)
{
	int		i;
	int		column;

	i = 0;
	column = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			column++;
		}
		i++;
	}
	ft_putchar('[');
	ft_putnbr(column);
	ft_putchar(']');
}

void	count_lines(char *buf)
{
	int		line;

	line = 0;
	while (buf[line] != '\n')
		line++;
	ft_putchar('[');
	ft_putnbr(line);
	ft_putchar(']');
}

void	name_bis(char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i++;
	if (buf[i - 1] == 'A')
		ft_putstr("[colle-02]");
	else if (buf[i - 1] == 'C')
	{
		while (buf[j] != '\0')
			j++;
		if (buf[j - 2] == 'C')
			ft_putstr("[colle-03]");
		else
			ft_putstr("[colle-04]");
	}
}

void	name(char *buf)
{
	if (buf[0] == 'o')
		ft_putstr("[colle-00]");
	else if (buf[0] == '/')
		ft_putstr("[colle-01]");
	else if (buf[0] == 'A')
		name_bis(buf);
	else
		ft_putstr("aucune\n");
}

int		main(void)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = 0;
	buf = malloc(sizeof(char) * BUF_SIZE + 1);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	name(buf);
	ft_putchar(' ');
	count_lines(buf);
	ft_putchar(' ');
	count_columns(buf);
	ft_putchar('\n');
}
