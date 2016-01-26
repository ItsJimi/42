/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 14:19:57 by jmaiquez          #+#    #+#             */
/*   Updated: 2015/07/26 23:32:07 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE_2_H
# define COLLE_2_H
# define BUF_SIZE 10

# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_strcmp(char *s1, char *s2);
int		pattern_0(int line, int column, char *buf);
int		pattern_1(int line, int column, char *buf);
int		pattern_2(int line, int column, char *buf);
int		pattern_3(int line, int column, char *buf);
int		pattern_4(int line, int column, char *buf);
void	putcolle(int line, int column, char *tcolle, int i);
void	put(int line, char *tcolle, int size, int column);

#endif
