/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:38 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 10:51:48 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

#include <iostream>

ZombieEvent::ZombieEvent(void) {
  std::srand(std::time(NULL) + std::clock());
  std::cout << "New event" << std::endl;
  return;
}

ZombieEvent::~ZombieEvent(void) {
  std::cout << "Delete event" << std::endl;
  return;
}

void ZombieEvent::setZombieType(std::string type) {
  this->_type = type;
  return;
}

Zombie* ZombieEvent::newZombie(std::string name) const {
  Zombie* zombie = new Zombie(name, this->_type);
  return zombie;
}

Zombie* ZombieEvent::randomChump() const {
  std::string names[12] = {"Rick", "Glenn", "Carol", "Negan", "Daryl", "Carl", "Andrea", "Rosita", "Hershel", "Sasha", "Abraham", "Morgan"};
  Zombie* zombie = this->newZombie(names[rand() % 12]);
  zombie->announce();
  return zombie;
}