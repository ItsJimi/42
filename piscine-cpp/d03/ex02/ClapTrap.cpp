/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 11:21:08 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 11:38:17 by jmaiquez         ###   ########.fr       */
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

void ClapTrap::rangedAttack(std::string const & target) {
  if (this->_hitPoints == 0) {
    std::cout << "CL4P-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "CL4P-TP " << this->_name << " attacks " << target << "at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
  return;
}

void ClapTrap::meleeAttack(std::string const & target) {
  if (this->_hitPoints == 0) {
    std::cout << "CL4P-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "CL4P-TP " << this->_name << " attacks " << target << "at melee, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
  return;
}

void ClapTrap::takeDamage(unsigned int amount) {
  this->_hitPoints = this->_hitPoints - (amount - this->_armorDamageReduction);
  if (this->_hitPoints < 0) {
    this->_hitPoints = 0;
  }
  std::cout << "CL4P-TP " << this->_name << " lost " << (amount - this->_armorDamageReduction) << " hit points, he have " << this->_hitPoints << "/" << this->_maxHitPoints << " now." << std::endl;
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