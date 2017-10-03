/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:16:40 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 14:36:14 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
  return;
}

HumanB::~HumanB(void) {
  return;
}

void HumanB::attack(void) {
  std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
  return;
}

void HumanB::setWeapon(Weapon& weapon) {
  this->_weapon = &weapon;
  return;
}