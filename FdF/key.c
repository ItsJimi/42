/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:23:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/28 11:24:18 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key(int keycode, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_putstr("KEYCODE : ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 53)
		str_exit(0, "ESC !");
	if (keycode == 123)
		mlx->decalx -= 10;
	if (keycode == 124)
		mlx->decalx += 10;
	if (keycode == 125)
		mlx->decaly += 10;
	if (keycode == 126)
		mlx->decaly -= 10;
	if (keycode == 69)
		mlx->dim++;
	if (keycode == 78)
		mlx->dim--;
	if (keycode == 67)
		mlx->space++;
	if (keycode == 75)
		mlx->space--;
	if (keycode == 106)
		mlx->perspx++;
	if (keycode == 64)
		mlx->perspx--;
	if (keycode == 79)
		mlx->perspy++;
	if (keycode == 80)
		mlx->perspy--;
	mlx->p = dep_point(mlx, mlx->p);
	draw_point(mlx, mlx->p);
	return (0);
}
