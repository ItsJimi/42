/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:17 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/14 19:14:35 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		count_case(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static t_point	***ft_realloc(t_point ***p, int nline)
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

static t_point	**define(char *line, int y, t_mlx *mlx)
{
	t_point	**point;
	char	**tab;
	int		nbr_case;
	int		x;

	x = 0;
	tab = ft_strsplit(line, ' ');
	nbr_case = count_case(tab);
	if (!(point = (t_point **)malloc(sizeof(**point) * nbr_case)))
		str_exit(-1, "parse.c : Error line 54");
	while (x < nbr_case)
	{
		if (gnl_error(tab[x]) == -1)
			str_exit(-1, "Are you fucking kidding me ?");
		point[x] = new_point(x, y, tab[x], mlx);
		x++;
	}
	if (x == 0)
		str_exit(-1, "Are you fucking kidding me ?");
	mlx->mapw = x;
	point[x] = NULL;
	return (point);
}

t_point			***parse(char *av, t_mlx *mlx)
{
	int		fd;
	int		y;
	int		error;
	char	*line;
	t_point	***point;

	y = 0;
	if (!(fd = open(av, O_RDONLY)))
		str_exit(-1, "Error open");
	if (!(point = (t_point ***)malloc(sizeof(***point))))
		str_exit(-1, "parse.c : Error line 76");
	while ((error = get_next_line(fd, &line)) > 0)
	{
		point[y] = define(line, y, mlx);
		point = ft_realloc(point, y + 1);
		free(line);
		y++;
	}
	mlx->maph = y;
	point[y] = NULL;
	if (error == 0 && y != 0)
		return (point);
	else
		str_exit(-1, "Error gnl");
	return (0);
}
