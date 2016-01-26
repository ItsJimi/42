/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 13:52:02 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/26 18:48:19 by jmaiquez         ###   ########.fr       */
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

t_point			***ft_realloc(t_point ***p, int nline)
{
	t_point		***tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = (t_point ***)malloc(sizeof(tmp) * (nline + 1));
	while (i != nline)
	{
		tmp[i] = p[i];
		i++;
	}
	free(p);
	p = tmp;
	return (p);
}

t_point			***parse(t_mlx *mlx, int fd)
{
	int		i;
	int		err;
	char	**tab;
	t_point	***point;
	char	*line;

	i = 0;
	if (!(point = (t_point ***)malloc(sizeof(point) * 2)))
		error("/!\\ parse.c line 76 : Malloc point /!\\");
	while ((err = get_next_line(fd, &line)) > 0)
	{
		if (!(point = ft_realloc(point, i + 1)))
			error("/!\\ parse.c line 76 : Malloc point /!\\");
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
