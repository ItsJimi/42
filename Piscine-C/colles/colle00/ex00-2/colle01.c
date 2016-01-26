/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 19:02:38 by malexand          #+#    #+#             */
/*   Updated: 2015/07/26 11:17:05 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);
int		ft_atoi(char *src);

void	ft_extremum_up(int x)
{
	int i;

	i = 0;
	ft_putchar('/');
	while (i++ < x - 2)
		ft_putchar('*');
	if (x != 1)
	{
		ft_putchar('\\');
	}
	ft_putchar('\n');
}

void	ft_extremum_down(int x)
{
	int i;

	i = 0;
	ft_putchar('\\');
	while (i++ < x - 2)
		ft_putchar('*');
	if (x != 1)
	{
		ft_putchar('/');
	}
	ft_putchar('\n');
}

void	colle(int x, int y)
{
	int i;
	int j;

	if (x > 0 && y > 0)
	{
		ft_extremum_up(x);
		i = 0;
		while (i < y - 2)
		{
			ft_putchar('*');
			if (x != 1)
			{
				j = 0;
				while (j++ < x - 2)
					ft_putchar(' ');
				ft_putchar('*');
			}
			ft_putchar('\n');
			i++;
		}
		i = 0;
		if (y != 1)
			ft_extremum_down(x);
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		colle(ft_atoi(argv[1]), ft_atoi(argv[2]));
	}
	return 0;
}