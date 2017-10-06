/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:53:47 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 15:30:20 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

/* CONSTRUCTORS */

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {
  return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon(src) {
  *this = src;
  return;
}

PlasmaRifle::~PlasmaRifle(void) {
  return;
}

/* MEMBERS */

void PlasmaRifle::attack(void) const {
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
  return;
}

/* OPERATORS */

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const & rhs) {
  this->_name = rhs.getName();
  this->_damages = rhs.getDamage();
  this->_APCost = rhs.getAPCost();
  return *this;
}