/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 16:11:47 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/19 19:28:04 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		resolve(char **argv, int x, int y)
{
	if (x == 8 && y == 9)
		return (1);
	
}

int		main(int argc, char **argv)
{
	int		x;
	int		y;
	int		nb_char;

	x = 0;
	y = 1;
	nb_char = 0;
	if (argc != 10)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	while (y < 10)
	{
		while ((argv[y][x] != '\0' && argv[y][x] <= '9' && argv[y][x] >= '1') 
				|| (argv[y][x] == '.' && argv[y][x] != '\0'))
		{
			x++;
		}
		nb_char += x;
		x = 0;
		y++;
	}
	if (nb_char != 81)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
}
