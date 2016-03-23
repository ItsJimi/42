/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:17 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/03/23 12:28:15 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		count_case(char **str, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) == 42)
			mlx->nbrstart++;
		i++;
	}
	return (i);
}

static t_point	***ft_realloc(t_point ***p, int nline, t_mlx *mlx)
{
	t_point		***tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(tmp = (t_point ***)malloc(sizeof(tmp) * (nline + 1))))
		str_exit(-1, "parse.c : Error line 33", mlx);
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
	nbr_case = count_case(tab, mlx);
	if (!(point = (t_point **)malloc(sizeof(*point) * nbr_case)))
		str_exit(-1, "parse.c : Error line 54", mlx);
	while (x < nbr_case)
	{
		if (gnl_error1(tab[x]) == -1)
			str_exit(-1, "Are you fucking kidding me ?", mlx);
		point[x] = new_point(x, y, tab[x], mlx);
		free(tab[x]);
		x++;
	}
	free(tab);
	if (x == 0)
		str_exit(-1, "Are you fucking kidding me ?", mlx);
	mlx->mapw = x;
	point[x] = NULL;
	return (point);
}

t_point			***parse(char *av, t_mlx *mlx, int error)
{
	int		i;
	int		fd;
	int		y;
	char	*line;
	t_point	***point;

	i = -1;
	y = 0;
	mlx->nbrstart = 0;
	if (!(fd = open(av, O_RDONLY)))
		str_exit(-1, "Error open\n", mlx);
	if (!(point = (t_point ***)malloc(sizeof(***point))))
		str_exit(-1, "parse.c : Error line 76", mlx);
	while ((error = get_next_line(fd, &line)) > 0)
	{
		i = parse_error(mlx, i, line);
		point[y] = define(line, y, mlx);
		point = ft_realloc(point, y + 1, mlx);
		free(line);
		y++;
	}
	close(fd);
	return (gnl_error2(point, mlx, error, y));
}
