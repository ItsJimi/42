/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsjimi <itsjimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:50:27 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/20 23:18:25 by itsjimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_ls.h"

void		putlst(t_list *list)
{
	ft_putstr(list->content);
	ft_putstr(" ");
}

void		putnofile(t_list *list)
{
	ft_putstr("ls: ");
	ft_putstr(list->content);
	ft_putendl(": No such file or directory");
}