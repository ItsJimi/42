/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:00:52 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 15:30:56 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

/* CONSTRUCTORS */

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {
  return;
}

PowerFist::PowerFist(PowerFist const & src) : AWeapon(src) {
  *this = src;
  return;
}

PowerFist::~PowerFist(void) {
  return;
}

/* MEMBERS */

void PowerFist::attack(void) const {
  std::cout << "* pschhh... SBAM! *" << std::endl;
  return;
}

/* OPERATORS */

PowerFist& PowerFist::operator=(PowerFist const & rhs) {
  this->_name = rhs.getName();
  this->_damages = rhs.getDamage();
  this->_APCost = rhs.getAPCost();
  return *this;
}