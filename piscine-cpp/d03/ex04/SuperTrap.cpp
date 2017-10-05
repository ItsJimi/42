/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:31:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 15:00:32 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

/* CONSTRUCTORS */

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name) {
  this->_hitPoints = FragTrap::_hitPoints;
  this->_maxHitPoints = FragTrap::_maxHitPoints;
  this->_energyPoints = NinjaTrap::_energyPoints;
  this->_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
  this->_level = 1;
  this->_meleeAttackDamage = NinjaTrap::_meleeAttackDamage;
  this->_rangedAttackDamage = FragTrap::_rangedAttackDamage;
  this->_armorDamageReduction = FragTrap::_armorDamageReduction;

  std::cout << "FR4G-TP created" << std::endl;

  return;
}

SuperTrap::SuperTrap(SuperTrap const & src) : ClapTrap(src.getName()), FragTrap(src.getName()), NinjaTrap(src.getName()) {
  std::cout << "FR4G-TP created" << std::endl;
  return;
}

SuperTrap::~SuperTrap(void) {
  std::cout << "FR4G-TP deleted" << std::endl;
  return;
}

/* MEMBERS */



/* OPERATORS */

SuperTrap& SuperTrap::operator=(SuperTrap const & rhs) {
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