/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:42:58 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/12 14:33:10 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*gnl_join(char *dst, char *src)
{
	char	*tmp;

	tmp = dst;
	if ((dst = ft_strjoin(tmp, src)) == NULL)
		return (NULL);
	free(tmp);
	return (dst);
}

static int		gnl_read(int const fd, char *save[fd])
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	while (!(ft_strchr(save[fd], '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		save[fd] = gnl_join(save[fd], buf);
	}
	return (ret);
}

static int		gnl_copy(int const fd, char *save[fd], char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (save[fd][i] != '\n' && save[fd][i] != '\0')
		i++;
	*line = ft_strsub(save[fd], 0, i);
	tmp = (char *)malloc(sizeof(tmp) * (ft_strlen(save[fd]) + 1));
	if (tmp == NULL)
		return (-1);
	ft_strcpy(tmp, &save[fd][i + 1]);
	ft_strclr(save[fd]);
	save[fd] = ft_strcpy(save[fd], tmp);
	free(tmp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static	char	*save[256];

	if (fd < 0 || line == NULL || fd > 256 || BUFF_SIZE <= 0)
		return (-1);
	if (!save[fd] && (!(save[fd] = (char *)malloc(sizeof(save[fd]) * 2))))
		return (-1);
	if (gnl_read(fd, &(*save)) < 0)
		return (-1);
	if (save[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (gnl_copy(fd, &(*save), line) < 0)
		return (-1);
	return (1);
}
