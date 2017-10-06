/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:43:37 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 13:59:07 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

/* CONSTRUCTORS */

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name), _APCost(apcost), _damages(damage)  {
  return;
}

AWeapon::AWeapon(AWeapon const & src) {
  *this = src;
  return;
}

AWeapon::~AWeapon(void) {
  return;
}

/* MEMBERS */

std::string AWeapon::getName(void) const {
  return this->_name;
}

int AWeapon::getAPCost(void) const {
  return this->_APCost;
}

int AWeapon::getDamage(void) const {
  return this->_damages;
}

/* OPERATORS */

AWeapon& AWeapon::operator=(AWeapon const & rhs) {
  this->_name = rhs.getName();
  this->_APCost = rhs.getAPCost();
  this->_damages = rhs.getDamage();
  return *this;
}