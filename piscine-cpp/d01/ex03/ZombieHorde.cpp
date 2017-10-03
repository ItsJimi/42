/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:38 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 11:30:35 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"

#include <iostream>

ZombieHorde::ZombieHorde(int N) {
  std::srand(std::time(NULL) + std::clock());
  this->_zombies = new Zombie[N];

  for (int i = 0; i < N; i++) {
    this->_zombies[i].init(this->_getRandomName(), "Hunter");
    this->_zombies[i].announce();
  }

  std::cout << "New Horde" << std::endl;
  return;
}

ZombieHorde::~ZombieHorde(void) {
  delete [] this->_zombies;
  std::cout << "Delete Horde" << std::endl;
  return;
}

std::string ZombieHorde::_getRandomName(void) {
  std::string names[12] = {"Rick", "Glenn", "Carol", "Negan", "Daryl", "Carl", "Andrea", "Rosita", "Hershel", "Sasha", "Abraham", "Morgan"};
  return (names[rand() % 12]);
}