/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 13:52:02 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/26 14:38:23 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_case(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
		i++;
	ft_putnbr(i);
	ft_putchar('\n');
	return (i);
}

static t_point	**define(char **tab, t_mlx *mlx, int i)
{
	int		x;
	int		count;
	t_point	**tmp;

	x = 0;
	count = count_case(tab);
	if (!(tmp = (t_point **)malloc(sizeof(*tmp) * (count + 1))))
		error("/!\\ parse.c line 33 : Malloc tmp /!\\");
	while (x < count)
	{
		if (!(tmp[x] = (t_point *)malloc(sizeof(*tmp[x]))))
			error("/!\\ parse.c line 37 : Malloc tmp[x] /!\\");
		tmp[x]->y = i * SPACE;
		tmp[x]->x = x * SPACE;
		tmp[x]->z = ft_atoi(tab[x]);
		x++;
	}
	mlx->sizex = x;
	return (tmp);
}

static int		count_lines(char *arg)
{
	int		fd;
	int		i;
	int		err;
	char	*test;

	i = 0;
	fd = open(arg, O_RDONLY);
	while ((err = get_next_line(fd, &test)) > 0)
		i++;
	close(fd);
	ft_putnbr(i);
	ft_putchar('\n');
	if (err == 0)
		return (i);
	else
		return (-1);
}

t_point			***parse(char *arg, t_mlx *mlx, int fd)
{
	int		i;
	int		err;
	char	**tab;
	t_point	***point;
	char	*line;

	i = 0;
	if (!(point = (t_point ***)malloc(sizeof(point) * (count_lines(arg)))))
		error("/!\\ parse.c line 76 : Malloc point /!\\");
	while ((err = get_next_line(fd, &line)) > 0)
	{
		tab = ft_strsplit(line, ' ');
		if (!(point[i] = define(tab, mlx, i)))
			error("/!\\ parse.c line 81 : Define /!\\");
		ft_putendl(line);
		free(tab);
		tab = NULL;
		i++;
	}
	ft_putchar('\n');
	mlx->sizey = i;
	if (err == 0)
		return (point);
	else
		return (NULL);
}
