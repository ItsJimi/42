/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 08:57:55 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 15:12:08 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* CONSTRUCTORS */

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
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

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src.getName()) {
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