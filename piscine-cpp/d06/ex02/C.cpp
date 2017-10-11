/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:37:55 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 17:38:00 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

/* CONSTRUCTORS */

C::C(void) {
  return;
}

C::C(C const & src) {
  *this = src;
  return;
}

C::~C(void) {
  return;
}

/* MEMBERS */

/* OPERATORS */

C& C::operator=(C const & rhs) {
  return *this;
}