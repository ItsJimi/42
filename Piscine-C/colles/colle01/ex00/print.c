/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmestrej <cmestrej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 17:49:19 by cmestrej          #+#    #+#             */
/*   Updated: 2015/07/19 18:18:28 by cmestrej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int j;
	int k;

	j = 1;
	(void)ac;
	while (j < 10)
	{
		k = 0;
		while (k < 9)
		{
			ft_putchar(av[j][k]);
			ft_putchar(' ');
			k++;
		}
		ft_putchar('\n');
		j++;
	}
	return (0);
}
