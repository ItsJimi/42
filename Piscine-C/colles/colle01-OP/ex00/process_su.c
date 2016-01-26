/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_su.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 16:11:15 by ymaiquez          #+#    #+#             */
/*   Updated: 2015/07/19 15:24:19 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		line(char c, char **argv, int y)
{
	int x;

	x = 0;
	while (x < 9)
	{
		if (argv[y][x] == c)
			return (0);
		x++;
	}
	return (1);
}

int		column(char c, char **argv, int x)
{
	int y;

	y = 1;
	while (y <= 9)
	{
		if (argv[y][x] == c)
			return (0);
		y++;
	}
	return (1);
}

int		block(char c, char **argv, int y, int x)
{
	int i;
	int j;

	i = (3 * (y / 3)) + 3;
	while ((3 * (y / 3)) < i)
	{
		j = (3 * (x / 3)) + 3;
		while ((3 * (x / 3)) < j)
		{
			if (argv[y][x] == c)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
	
int		resolve(char **argv, int pos)
{
	int y;
	int x;
	char c;

	y = (pos + 9) / 9;
	x = pos % 9;
	c = '1';
	if (pos == 81)
		return (1);
	if (argv[y][x] != '.')
		return (resolve(argv, pos + 1));
	while (c <= '9')
	{
		if (line(c, argv, y) == 1 
			&& column(c, argv, x) == 1 && block(c, argv, y, x) == 1)
		{
			argv[y][x] = c;
		}
		c++;
	}
	argv[y][x] = '.';
	return (0);
}
