/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:12:07 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 14:36:21 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
  return;
}

HumanA::~HumanA(void) {
  return;
}

void HumanA::attack(void) {
  std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
  return;
}