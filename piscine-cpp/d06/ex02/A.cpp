/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:36:09 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 17:36:14 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

/* CONSTRUCTORS */

A::A(void) {
  return;
}

A::A(A const & src) {
  *this = src;
  return;
}

A::~A(void) {
  return;
}

/* MEMBERS */

/* OPERATORS */

A& A::operator=(A const & rhs) {
  return *this;
}