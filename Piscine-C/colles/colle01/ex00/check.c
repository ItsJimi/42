/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruellou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 16:49:19 by aruellou          #+#    #+#             */
/*   Updated: 2015/07/19 19:18:14 by aruellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		line(char **argv, int y, char c)
{
	int i;

	i = 0;
	while (argv[y][i] != c)
	{
		if (i == 8)
			return (1);
		i++;
	}
	return (0);
}

int		col(char **argv, int x, char c)
{
	int i;

	i = 0;
	while (argv[i][x] != c)
	{
		if (i == 8)
			return (1);
		i++;
	}
	return (0);
}

int		box(char **argv, int x, int y, char c)
{
	int i;
	int j;

	j = 0;
	while (argv[j][x] != c && j < 3
			&& argv[j][x] != argv[(y / 3) * 3][(x / 3) * 3])
	{
		i = 0;
		while (argv[y][i] != c && i < 3 && argv[j][x] != argv[y][(x / 3) * 3])
		{
			i++;
		}
		if (i == 3 && j == 3)
			return (1);
		j++;
	}
	return (0);
}
