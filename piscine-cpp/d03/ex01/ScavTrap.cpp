/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:53:59 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 11:15:50 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

/* CONSTRUCTORS */

ScavTrap::ScavTrap(std::string name) {
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

  std::cout << "SC4V-TP created" << std::endl;

  return;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
  std::srand(std::time(NULL) + std::clock());
  this->_name = src.getName();
  *this = src;

  std::cout << "SC4V-TP created" << std::endl;

  return;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "SC4V-TP deleted" << std::endl;

  return;
}

/* MEMBERS */

void ScavTrap::rangedAttack(std::string const & target) {
  if (this->_hitPoints == 0) {
    std::cout << "SC4V-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "SC4V-TP " << this->_name << " attacks " << target << "at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
  return;
}

void ScavTrap::meleeAttack(std::string const & target) {
  if (this->_hitPoints == 0) {
    std::cout << "SC4V-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "SC4V-TP " << this->_name << " attacks " << target << "at melee, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
  return;
}

void ScavTrap::takeDamage(unsigned int amount) {
  this->_hitPoints = this->_hitPoints - (amount - this->_armorDamageReduction);
  if (this->_hitPoints < 0) {
    this->_hitPoints = 0;
  }
  std::cout << "SC4V-TP " << this->_name << " lost " << (amount - this->_armorDamageReduction) << " hit points, he have " << this->_hitPoints << "/" << this->_maxHitPoints << " now." << std::endl;
  return;
}

void ScavTrap::beRepaired(unsigned int amount) {
  this->_hitPoints = this->_hitPoints + amount;
  if (this->_hitPoints > this->_maxHitPoints) {
    this->_hitPoints = this->_maxHitPoints;
  }
  std::cout << "SC4V-TP " << this->_name << " win " << amount << " hit points, he have " << this->_hitPoints << "/" << this->_maxHitPoints << " now." << std::endl;
  return;
}

void ScavTrap::challengeNewcomer(void) {
  if (this->_hitPoints == 0) {
    std::cout << "SC4V-TP " << this->_name << " can't challenge because he have'nt hit points."<< std::endl;
    return;
  }
  std::string challenges[5] = {"dance", "sing", "jump", "swim", "cook"};
  std::cout << "SC4V-TP " << this->_name << " challenge you with " << challenges[rand() % 5] << " game." << std::endl;
  return;
}

/* OPERATORS */

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs) {
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

unsigned int ScavTrap::getLevel(void) const {
	return this->_level;
}

unsigned int ScavTrap::gethitPoints(void) const {
	return this->_hitPoints;
}

unsigned int ScavTrap::getmaxHitPoints(void) const {
	return this->_maxHitPoints;
}

int ScavTrap::getenergyPoints(void) const {
	return this->_energyPoints;
}

int ScavTrap::getmaxEnergyPoints(void) const {
	return this->_maxEnergyPoints;
}

int ScavTrap::getmeleeAttackDamage(void) const {
	return this->_meleeAttackDamage;
}

int ScavTrap::getrangedAttackDamage(void) const {
	return this->_rangedAttackDamage;
}

int ScavTrap::getarmorDamageReduction(void) const {
	return this->_armorDamageReduction;
}

std::string ScavTrap::getName(void) const {
	return this->_name;
}