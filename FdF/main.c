/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 12:28:27 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/26 14:03:55 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error(char *str)
{
	ft_putstr(str);
	exit(-1);
}

int		key(int keycode)
{
	ft_putstr("KEYCODE : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
	{
		ft_putstr("ESC !");
		exit(0);
	}
	return (0);
}

t_line	*init_line(void)
{
	t_line	*line;

	if (!(line = (t_line *)malloc(sizeof(*line))))
		error("/!\\ main.c line 42 : Malloc line /!\\");
	line->x1 = 0;
	line->x2 = 0;
	line->y1 = 0;
	line->y2 = 0;
	return (line);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_point	***point;
	t_line	*line;
	int		fd;

	line = init_line();
	if (!(mlx = (t_mlx*)malloc(sizeof(*mlx))))
		error("/!\\ main.c line 42 : Malloc mlx /!\\");
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "====[ F D F ]====");
	mlx->sizey = 0;
	if (argc > 1)
	{
		ft_putstr("--- PARSE ---\n");
		if (!(fd = open(argv[1], O_RDONLY)))
			error("/!\\ main.c line 52 : Open /!\\");
		if (!(point = parse(argv[1], mlx, fd)))
			error("/!\\ main.c line 54 : Parse /!\\");
		draw(mlx, line, point);
		draw2(mlx, line, point);
	}
	mlx_key_hook(mlx->win, key, mlx);
	mlx_loop(mlx);
	return (0);
}
