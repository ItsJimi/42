/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 12:28:27 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/26 22:15:28 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error(char *str)
{
	ft_putstr(str);
	exit(0);
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
	//t_line	*line;

	if (argc == 2)
	{
		if (!(mlx = (t_mlx *)malloc(sizeof(*mlx))))
			error("/!\\ main.c line 42 : Malloc mlx /!\\");
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, 1200, 1200, "F D F");
		argv[0][1] = 'a';
		//ft_putstr("--- PARSE ---\n");
		//line = init_line();
		mlx->point = parse(argv[1], mlx);
		//draw(mlx, line, point);
		//draw2(mlx, line, point);
		mlx_key_hook(mlx->win, key, mlx);
		mlx_loop(mlx->mlx);
	}
	return (0);
}
