/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 11:19:50 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/12 15:59:21 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line(int x)
{
	int	i;

	i = 2;
	ft_putchar('/');
	while (i < x)
	{
		ft_putchar('*');
		i++;
	}
	if (x > 1)
	{
		ft_putchar('\\');
	}
	ft_putchar('\n');
}

void	last_line(int x)
{
	int	i;

	i = 2;
	ft_putchar('\\');
	while (i < x)
	{
		ft_putchar('*');
		i++;
	}
	if (x > 1)
	{
		ft_putchar('/');
	}
	ft_putchar('\n');
}

void	other_lines(int x, int y)
{
	int	j;
	int	k;

	j = 2;
	k = 2;
	if (y > 1)
	{
		while (j < y)
		{
			ft_putchar('*');
			while (k < x)
			{
				ft_putchar(' ');
				k++;
			}
			if (x > 1)
			{
				ft_putchar('*');
			}
			ft_putchar('\n');
			k = 2;
			j++;
		}
		last_line(x);
	}
}

void	colle(int x, int y)
{
	if (x > 0 && y > 0)
	{
		first_line(x);
		other_lines(x, y);
	}
}
