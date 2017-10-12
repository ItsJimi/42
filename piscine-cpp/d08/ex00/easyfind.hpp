/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:14:42 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/12 15:27:12 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template <typename T>
void easyfind(T container, int n) {
  for (int i = 0; container[i]; i++) {
    if (container[i] == n) {
      return i;
    }
  }
  return;
}

#endif