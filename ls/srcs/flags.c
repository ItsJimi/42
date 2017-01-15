/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsjimi <itsjimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:36:48 by itsjimi           #+#    #+#             */
/*   Updated: 2017/01/15 14:37:21 by itsjimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

static void	if_exists(char *flags, char c, int *k)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
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
		ft_putstr("\nusage: ls [-lRart] [file ...]\n");
		exit(-1);
	}
}

void		check_flags(int ac, char **av, char *flags)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
			return ;
		j = 1;
		while (av[i][j])
		{
			if_exists(flags, av[i][j], &k);
			j++;
		}
		i++;
	}
	return ;
}