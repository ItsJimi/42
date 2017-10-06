/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:26:14 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 15:31:17 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

/* CONSTRUCTORS */

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
  return;
}

SuperMutant::SuperMutant(SuperMutant const & src) : Enemy(src) {
  *this = src;
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
  return;
}

SuperMutant::~SuperMutant(void) {
  std::cout << "Aaargh ..." << std::endl;
  return;
}

/* MEMBERS */

void SuperMutant::takeDamage(int damages) {
  if (damages <= 0) {
    return;
  }
  this->_hitPoints = (this->_hitPoints - damages + 3 <= 0) ? 0 : this->_hitPoints - damages + 3;
  return;
}

/* OPERATORS */

SuperMutant& SuperMutant::operator=(SuperMutant const & rhs) {
  this->_hitPoints = rhs.getHP();
  this->_type = rhs.getType();
  return *this;
}