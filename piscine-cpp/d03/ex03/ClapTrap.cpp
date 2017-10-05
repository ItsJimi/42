/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 11:21:08 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 15:10:04 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTRUCTORS */

ClapTrap::ClapTrap(std::string name) {
  std::srand(std::time(NULL) + std::clock());
  this->_name = name;

  this->_hitPoints = 100;
  this->_maxHitPoints = 100;
  this->_energyPoints = 50;
  this->_maxEnergyPoints = 50;
  this->_level = 1;
  this->_meleeAttackDamage = 20;
  this->_rangedAttackDamage = 15;
  this->_armorDamageReduction = 3;

  std::cout << "CL4P-TP created" << std::endl;

  return;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
  std::srand(std::time(NULL) + std::clock());
  this->_name = src.getName();
  *this = src;

  std::cout << "CL4P-TP created" << std::endl;

  return;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "CL4P-TP deleted" << std::endl;

  return;
}

/* MEMBERS */

void ClapTrap::takeDamage(unsigned int amount) {
  int damages = amount - this->_armorDamageReduction;
  if (damages <= 0) {
    std::cout << "CL4P-TP " << this->_name << " lost 0 hit points" << std::endl;
    return;
  }
  if ((int)(this->_hitPoints - damages) < 0) {
    this->_hitPoints = 0;
  } else {
    this->_hitPoints = this->_hitPoints - (amount - this->_armorDamageReduction);
  }
  std::cout << "CL4P-TP " << this->_name << " lost " << damages << " hit points, he have " << this->_hitPoints << "/" << this->_maxHitPoints << " now." << std::endl;
  return;
}

void ClapTrap::beRepaired(unsigned int amount) {
  this->_hitPoints = this->_hitPoints + amount;
  if (this->_hitPoints > this->_maxHitPoints) {
    this->_hitPoints = this->_maxHitPoints;
  }
  std::cout << "CL4P-TP " << this->_name << " win " << amount << " hit points, he have " << this->_hitPoints << "/" << this->_maxHitPoints << " now." << std::endl;
  return;
}

/* OPERATORS */

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs) {
  this->_hitPoints = rhs.gethitPoints();
  this->_maxHitPoints = rhs.getmaxHitPoints();
  this->_energyPoints = rhs.getenergyPoints();
  this->_maxEnergyPoints = rhs._maxEnergyPoints;
  this->_level = rhs.getLevel();
  this->_meleeAttackDamage = rhs.getmeleeAttackDamage();
  this->_rangedAttackDamage = rhs.getrangedAttackDamage();
  this->_armorDamageReduction = rhs.getarmorDamageReduction();
  return *this;
}


/* GETTERS */

unsigned int ClapTrap::getLevel(void) const {
	return this->_level;
}

unsigned int ClapTrap::gethitPoints(void) const {
	return this->_hitPoints;
}

unsigned int ClapTrap::getmaxHitPoints(void) const {
	return this->_maxHitPoints;
}

int ClapTrap::getenergyPoints(void) const {
	return this->_energyPoints;
}

int ClapTrap::getmaxEnergyPoints(void) const {
	return this->_maxEnergyPoints;
}

int ClapTrap::getmeleeAttackDamage(void) const {
	return this->_meleeAttackDamage;
}

int ClapTrap::getrangedAttackDamage(void) const {
	return this->_rangedAttackDamage;
}

int ClapTrap::getarmorDamageReduction(void) const {
	return this->_armorDamageReduction;
}

std::string ClapTrap::getName(void) const {
	return this->_name;
}