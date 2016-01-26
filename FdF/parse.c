/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 13:52:02 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/26 20:31:31 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_case(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
		i++;
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
	//tmp[x] = NULL;
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

void	put_points(t_point ***points)
{
	int		i;
	int		j;

	i = 0;
	while (points[i])
	{
		j = 0;
		while (points[i][j])
		{
			ft_putnbr((points[i][j])->x);
			ft_putstr(", ");
			ft_putnbr((points[i][j])->y);
			ft_putstr(", ");
			ft_putnbr((points[i][j])->z);
			ft_putchar('\n');
			j++;
		}
		i++;
	}
	ft_putstr("All points done\n");
}

t_point			***parse(t_mlx *mlx, int fd)
{
	int		i;
	int		err;
	char	**tab;
	t_point	***point;
	char	*line;

	i = 0;
	if (!(point = (t_point ***)malloc(sizeof(point) * 1)))
		error("/!\\ parse.c line 78 : Malloc point /!\\");
	while ((err = get_next_line(fd, &line)) > 0)
	{
		if (!(point = ft_realloc(point, i + 1)))
			error("/!\\ parse.c line 82 : Malloc point /!\\");
		tab = ft_strsplit(line, 32);
		if (!(point[i] = define(tab, mlx, i)))
			error("/!\\ parse.c line 85 : Define /!\\");
		tab = NULL;
		i++;
	}
	point[i] = NULL;
	mlx->sizey = i;
	//put_points(point);
	if (err == 0)
		return (point);
	else
		return (NULL);
}
