/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:56:55 by malexand          #+#    #+#             */
/*   Updated: 2015/07/30 20:04:46 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		open_file(char *input)
{
	int fd;

	fd = open(input, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error open()");
		return (0);
	}
	return (fd);
}

int		close_file(int handle)
{
	if (close(handle) < 0)
	{
		ft_putstr("Error close()");
		return (0);
	}
	return (1);
}

int		read_file(int input, char *dest)
{
	int		size;
	char	buffer[1];
	int		count;
	int		i;

	i = 10000;
	size = 0;
	while ((count = read(input, buffer, BUFFER_SIZE)) > 0)
	{
		dest[size] = buffer[0];
		size++;
	}
	dest[size] = '\0';
	while (i > size + 1)
	{
		dest[i] = '\0';
		i--;
	}
	return (count);
}
