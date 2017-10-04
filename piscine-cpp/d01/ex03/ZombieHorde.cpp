/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:38 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/04 18:13:04 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"

#include <iostream>

ZombieHorde::ZombieHorde(int N) : _nbrZombies(N) {
  std::srand(std::time(NULL) + std::clock());
  this->_zombies = new Zombie[N];

  for (int i = 0; i < N; i++) {
    this->_zombies[i].init(this->_getRandomName(), "Hunter");
  }

  this->announce();

  std::cout << "Horde created" << std::endl;
  return;
}

ZombieHorde::~ZombieHorde(void) {
  delete [] this->_zombies;
  std::cout << "Horde deleted" << std::endl;
  return;
}

std::string ZombieHorde::_getRandomName(void) {
  std::string names[12] = {"Rick", "Glenn", "Carol", "Negan", "Daryl", "Carl", "Andrea", "Rosita", "Hershel", "Sasha", "Abraham", "Morgan"};
  return (names[rand() % 12]);
}

void ZombieHorde::announce(void) const {
  for (int i = 0; i < this->_nbrZombies; i++) {
    this->_zombies[i].announce();
  }
  return;
}