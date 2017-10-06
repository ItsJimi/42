/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:39:10 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 15:50:03 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* CONSTRUCTORS */

Character::Character(std::string const & name) : _name(name), _AP(40), _weapon(NULL) {
  return;
}

Character::Character(Character const & src) {
  *this = src;
  return;
}

Character::~Character(void) {
  return;
}

/* MEMBERS */

void Character::recoverAP(void) {
  this->_AP = (this->_AP + 10 >= 40) ? 40 : this->_AP + 10;
  return;
}

void Character::equip(AWeapon* weapon) {
  this->_weapon = weapon;
  return;
}

void Character::attack(Enemy* enemy) {
  if (!this->_weapon || !enemy) {
    return;
  }
  if (this->_AP < this->_weapon->getAPCost()) {
    std::cout << "No AP" << std::endl;
    return;
  }
  std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
  this->_weapon->attack();
  this->_AP = (this->_AP - this->_weapon->getAPCost() <= 0) ? 0 : this->_AP - this->_weapon->getAPCost();
  enemy->takeDamage(this->_weapon->getDamage());
  if (enemy->getHP() <= 0) {
    enemy = NULL;
    delete enemy;
  }
  return;
}

std::string Character::getName(void) const {
  return this->_name;
}

int Character::getAP(void) const {
  return this->_AP;
}

AWeapon *Character::getWeapon(void) const {
  return this->_weapon;
}

/* OPERATORS */

Character& Character::operator=(Character const & rhs) {
  this->_name = rhs.getName();
  return *this;
}

std::ostream & operator<<(std::ostream & stream, Character const & rhs) {
  if (!rhs.getWeapon()) {
    stream << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
    return stream;
  }
  stream << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
  return stream;
}