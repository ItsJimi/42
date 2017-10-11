/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:36:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 17:36:43 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

/* CONSTRUCTORS */

B::B(void) {
  return;
}

B::B(B const & src) {
  *this = src;
  return;
}

B::~B(void) {
  return;
}

/* MEMBERS */

/* OPERATORS */

B& B::operator=(B const & rhs) {
  return *this;
}