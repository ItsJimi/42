/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:33:35 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 15:31:23 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

/* CONSTRUCTORS */

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion") {
  std::cout << "* click click click *" << std::endl;
  return;
}

RadScorpion::RadScorpion(RadScorpion const & src) : Enemy(src) {
  *this = src;
  std::cout << "* click click click *" << std::endl;
  return;
}

RadScorpion::~RadScorpion(void) {
  std::cout << "* SPROTCH *" << std::endl;
  return;
}

/* MEMBERS */

/* OPERATORS */

RadScorpion& RadScorpion::operator=(RadScorpion const & rhs) {
  this->_hitPoints = rhs.getHP();
  this->_type = rhs.getType();
  return *this;
}