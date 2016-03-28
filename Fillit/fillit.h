/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:09:57 by jmaiquez          #+#    #+#             */
/*   Updated: 2016/01/07 16:19:13 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	**define_patterns(int patterns, char *buf);
void	holy_resolve(char **tab, int patterns);
int		check_letter(char **tryresult, int patterns);
int		check_valid_point(char *tab, char **tryresult, int i, int j);
void	place_pattern(char *tab, char **tryresult, int i, int j);
int		check_republic(int k, char **tryresult);
int		ft_isupper(char c);
void	holy_point(char *tryresult, int x);
void	putabl(char **tabl);
void	holy_letter(char **tryresult);
int		resolve(char **tab, char **tryresult, int *pattern, int x);
char	**holy_result(int x);
void	ft_putchar(const char c);
void	ft_putstr(const char *s);
size_t	ft_strlen(const char *s);

#endif
