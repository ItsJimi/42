/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsjimi <itsjimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:01:18 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/15 17:28:29 by itsjimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <sys/xattr.h>

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd 	t_passwd;
typedef struct group 	t_group;

void		check_flags(int ac, char **av, char *flags);
int			open_dir(char *str, int sneaky);

#endif
