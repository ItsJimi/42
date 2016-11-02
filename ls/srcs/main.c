/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:00:03 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/11/02 17:01:53 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char	*error;
	char	*flags;

	flags = ['l', 'R', 'a', 'r', 't'];
	if (argc > 1)
	{
		if (argv[1][0] == '-')
		{
			if ()
			{
				if (ft_strchr(argv[1], 'l') != NULL)
				{
					ft_putstr("l");
				}
				if (ft_strchr(argv[1], 'R') != NULL)
				{
					ft_putstr("R");
				}
				if (ft_strchr(argv[1], 'a') != NULL)
				{
					ft_putstr("a");
				}
				if (ft_strchr(argv[1], 'r') != NULL)
				{
					ft_putstr("r");
				}
				if (ft_strchr(argv[1], 't') != NULL)
				{
					ft_putstr("t");
				}
			}
			else
			{
				if(!(error = (char *)malloc(sizeof(*error) * ft_strlen(argv[1]))))
				{
					ft_putstr("malloc error");
					return(0);
				}
				error = ft_strsplit(argv[1], '-')[1];
				ft_putstr("ls: illegal option ");
				ft_putstr(error);
			}
		}
		else
		{
			ft_putstr("directories");
		}
	}
	else
	{
		ft_putstr("files");
	}
	return (0);
}
