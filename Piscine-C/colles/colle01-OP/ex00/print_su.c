/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_su.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 14:56:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/19 15:27:56 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		resolve(char **argv, int pos);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	putgrid(char **argv)
{
	int y;
	int x;

	y = 1;
	x = 0;
	while (argv[y] != '\0')
	{
		while (argv[y][x] != '\0')
		{
			ft_putchar(argv[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 10)
	{
		resolve(argv, 0);
		putgrid(argv);
	}
	else if (argc != 10)
	{
		write (1, "Erreur\n", 7);
	}
	return (0);
}
