/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:38 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 10:43:29 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {
  return;
}

Zombie::~Zombie(void) {
  std::cout << "Zombie deleted" << std::endl;
  return;
}

void Zombie::announce(void) const {
  std::cout << "<" << this->_name << " (" << this->_type << ")> Miam ! Un humaiiiiiin..." << std::endl;
  return;
}