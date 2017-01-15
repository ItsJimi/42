/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsjimi <itsjimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:36:03 by itsjimi           #+#    #+#             */
/*   Updated: 2017/01/15 15:43:39 by itsjimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

int		open_dir(char *str, int sneaky)
{
	DIR				*dir;
	t_dirent		*ent;

	if ((dir = opendir(str)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			if (ent->d_name[0] != '.' || sneaky == 1)
			{
				ft_putstr(ent->d_name);
				ft_putchar(' ');
			}
		}
		ft_putchar('\n');
		closedir(dir);
		return (1);
	}
	else
	{
		ft_putendl(str);
		return (0);
	}
}