/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 14:17:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/26 23:31:43 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"

int		count_columns(char *buf)
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
	return (column);
}

int		count_lines(char *buf)
{
	int		line;

	line = 0;
	while (buf[line] && buf[line] != '\n')
		line++;
	return (line);
}

void	name(int line, int column, char *buf, char *tcolle)
{
	int i;

	i = 0;
	while (i < 6)
		tcolle[i++] = '\0';
	i = 0;
	if (pattern_0(line, column, buf))
		tcolle[i++] = '0';
	if (pattern_1(line, column, buf))
		tcolle[i++] = '1';
	if (pattern_2(line, column, buf))
		tcolle[i++] = '2';
	if (pattern_3(line, column, buf))
		tcolle[i++] = '3';
	if (pattern_4(line, column, buf))
		tcolle[i++] = '4';
}

char	*ft_joinstr(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*new;
	int		i;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	i = -1;
	while (++i < len1)
		new[i] = s1[i];
	i = -1;
	while (++i < len2)
		new[i + len1] = s2[i];
	new[len1 + len2] = '\0';
	free(s1);
	return (new);
}

int		main(void)
{
	int		ret;
	int		size;
	char	buf[BUF_SIZE + 1];
	char	*input;
	char	tcolle[6];

	size = 0;
	input = malloc(sizeof(char) * 1);
	input[0] = '\0';
	while ((ret = read(0, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		input = ft_joinstr(input, buf);
	}
	name(count_lines(input), count_columns(input), input, tcolle);
	while (tcolle[size] != '\0')
		size++;
	put(count_lines(input), tcolle, size, count_columns(input));
}
