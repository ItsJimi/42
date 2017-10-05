/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 08:57:55 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 11:43:54 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* CONSTRUCTORS */

FragTrap::FragTrap(std::string name) {
  std::srand(std::time(NULL) + std::clock());
  this->_name = name;

  this->_hitPoints = 100;
  this->_maxHitPoints = 100;
  this->_energyPoints = 100;
  this->_maxEnergyPoints = 100;
  this->_level = 1;
  this->_meleeAttackDamage = 30;
  this->_rangedAttackDamage = 20;
  this->_armorDamageReduction = 5;

  std::cout << "FR4G-TP created" << std::endl;

  return;
}

FragTrap::FragTrap(FragTrap const & src) {
  std::srand(std::time(NULL) + std::clock());
  this->_name = src.getName();
  *this = src;

  std::cout << "FR4G-TP created" << std::endl;

  return;
}

FragTrap::~FragTrap(void) {
  std::cout << "FR4G-TP deleted" << std::endl;
  return;
}

/* MEMBERS */

void FragTrap::rangedAttack(std::string const & target) {
  if (this->_hitPoints == 0) {
    std::cout << "FR4G-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "FR4G-TP " << this->_name << " attacks " << target << "at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
  return;
}

void FragTrap::meleeAttack(std::string const & target) {
  if (this->_hitPoints == 0) {
    std::cout << "FR4G-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "FR4G-TP " << this->_name << " attacks " << target << "at melee, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
  return;
}

void FragTrap::takeDamage(unsigned int amount) {
  this->_hitPoints = this->_hitPoints - (amount - this->_armorDamageReduction);
  if (this->_hitPoints < 0) {
    this->_hitPoints = 0;
  }
  std::cout << "FR4G-TP " << this->_name << " lost " << (amount - this->_armorDamageReduction) << " hit points, he have " << this->_hitPoints << "/" << this->_maxHitPoints << " now." << std::endl;
  return;
}

void FragTrap::beRepaired(unsigned int amount) {
  this->_hitPoints = this->_hitPoints + amount;
  if (this->_hitPoints > this->_maxHitPoints) {
    this->_hitPoints = this->_maxHitPoints;
  }
  std::cout << "FR4G-TP " << this->_name << " win " << amount << " hit points, he have " << this->_hitPoints << "/" << this->_maxHitPoints << " now." << std::endl;
  return;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
  if (this->_hitPoints == 0) {
    std::cout << "FR4G-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  if (this->_energyPoints <= 0) {
    std::cout << "No energy available." << std::endl;
    return;
  }
  this->_energyPoints -= 25;
  if (this->_energyPoints < 0) {
    this->_energyPoints = 0;
  }
  std::string attacks[5] = {"Fire ball", "Mega punch", "Sneaky", "Strangulation", "CS Coupe"};
  std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with " << attacks[rand() % 5] << " attack, he have " << this->_energyPoints << "/" << this->_maxEnergyPoints << " energy points now." << std::endl;
  return;
}

/* OPERATORS */

FragTrap& FragTrap::operator=(FragTrap const & rhs) {
  this->_hitPoints = rhs.gethitPoints();
  this->_maxHitPoints = rhs.getmaxHitPoints();
  this->_energyPoints = rhs.getenergyPoints();
  this->_maxEnergyPoints = rhs.getmaxEnergyPoints();
  this->_level = rhs.getLevel();
  this->_meleeAttackDamage = rhs.getmeleeAttackDamage();
  this->_rangedAttackDamage = rhs.getrangedAttackDamage();
  this->_armorDamageReduction = rhs.getarmorDamageReduction();
  return *this;
}


/* GETTERS */

unsigned int FragTrap::getLevel(void) const {
	return this->_level;
}

unsigned int FragTrap::gethitPoints(void) const {
	return this->_hitPoints;
}

unsigned int FragTrap::getmaxHitPoints(void) const {
	return this->_maxHitPoints;
}

int FragTrap::getenergyPoints(void) const {
	return this->_energyPoints;
}

int FragTrap::getmaxEnergyPoints(void) const {
	return this->_maxEnergyPoints;
}

int FragTrap::getmeleeAttackDamage(void) const {
	return this->_meleeAttackDamage;
}

int FragTrap::getrangedAttackDamage(void) const {
	return this->_rangedAttackDamage;
}

int FragTrap::getarmorDamageReduction(void) const {
	return this->_armorDamageReduction;
}

std::string FragTrap::getName(void) const {
	return this->_name;
}