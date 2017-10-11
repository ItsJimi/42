/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:34:47 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 17:52:10 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/* CONSTRUCTORS */

Base::Base(void) {
  return;
}

Base::Base(Base const & src) {
  *this = src;
  return;
}

Base::~Base(void) {
  return;
}

/* MEMBERS */

/* OPERATORS */

Base& Base::operator=(Base const & rhs) {
  return *this;
}