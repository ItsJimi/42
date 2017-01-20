/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:36:48 by itsjimi           #+#    #+#             */
/*   Updated: 2017/01/20 15:47:20 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

static void	if_exists(char *flags, char c, int *k)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't' || c == 's')
	{
		if (ft_strchr(flags, c) == NULL)
		{
			flags[*k] = c;
			*k = *k + 1;
		}
	}
	else
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(c);
		ft_putstr("\nusage: ls [-lRarts] [file ...]\n");
		exit(-1);
	}
}

int			check_flags(char **av, char *flags)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	while (av[i])
	{
		if (av[i][0] != '-')
			return (i);
		j = 1;
		while (av[i][j])
		{
			if_exists(flags, av[i][j], &k);
			j++;
		}
		i++;
	}
	return (1);
}
