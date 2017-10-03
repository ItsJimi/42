/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:05:49 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 14:36:33 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
  return;
}

Weapon::~Weapon(void) {
  return;
}

std::string Weapon::getType(void) const {
  return this->_type;
}

void Weapon::setType(std::string type) {
  this->_type = type;
  return;
}