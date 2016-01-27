/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 13:52:02 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/26 22:15:27 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_case(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == 32 && str[i])
			i++;
		while (str[i] != 32 && str[i])
			i++;
		j++;
	}
	if (str[i - 1] == 32)
		j--;
	return (j);
}

t_point	*ft_pointnew(int x, int y, int z)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

static t_point	**define(char *line, t_mlx *mlx, int i)qq
{
	int		x;
	int		count;
	char	**tab;
	t_point	**tmp;

	x = 0;
	count = count_case(line);
	tab = ft_strsplit(line, 32);
	if (!(tmp = (t_point **)malloc(sizeof(*tmp) * (count + 3))))
		error("/!\\ parse.c line 33 : Malloc tmp /!\\");
	while (x < count)
	{
		tmp[x] = ft_pointnew(x, i, ft_atoi(tab[x]));
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

t_point			***parse(char *av, t_mlx *mlx)
{
	int		i;
	int		fd;
	int		err;
	t_point	***point;
	char	*line;

	i = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	if (!(point = (t_point ***)malloc(sizeof(point) * 2)))
		return (NULL);
	while ((err = get_next_line(fd, &line)) > 0)
	{
		point[i] = define(line, mlx, i);
			//error("/!\\ parse.c line 85 : Define /!\\");
		point = ft_realloc(point, i + 1);
			//error("/!\\ parse.c line 82 : Malloc point /!\\");
		i++;
	}
	//point[i] = NULL;
	mlx->sizey = i;
	//put_points(point);
	return (point);
}
