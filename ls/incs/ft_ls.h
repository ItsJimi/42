/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:01:18 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/01/23 14:06:42 by jmaiquez         ###   ########.fr       */
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
typedef struct passwd	t_passwd;
typedef struct group	t_group;

void		putlst(t_list *list);
void		putnofile(t_list *list);
void		putinfos(t_list *list);
int			check_flags(char **av, char *flags);
t_list		*open_dir(char *str, int sneaky, int sort);

#endif
