/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 10:11:02 by malexand          #+#    #+#             */
/*   Updated: 2015/07/30 20:09:19 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		main(int ac, char **av)
{
	char	*save;
	int		i;

	i = 1;
	save = malloc(200000000);
	if (ac > 1)
	{
		while (ac > i)
		{
			read_file(open_file(av[i]), save);
			if (do_operation_map(save) < 1)
			{
				ft_putstr("map error\n");
				return (0);
			}
			i++;
		}
	}
	else
	{
		read_file(0, save);
		if (do_operation_map(save) != 1)
			return (0);
	}
	return (0);
}
