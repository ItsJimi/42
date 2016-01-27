/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:20:21 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/27 13:55:04 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     str_exit(int error, char *str)
{
    ft_putstr(str);
    ft_putchar('\n');
    exit(error);
}

int		key(int keycode)
{
	ft_putstr("KEYCODE : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
	   str_exit(0, "ESC !");
	return (0);
}

int     main(int ac, char **av)
{
    t_mlx   *mlx;

    if (!(mlx = (t_mlx *)malloc(sizeof(*mlx))))
        str_exit(-1, "Error");
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, 1000, 1000, "===[ F D F ]===");
    mlx_loop(mlx->mlx);
}
