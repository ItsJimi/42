/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:53:59 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 16:02:18 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

/* CONSTRUCTORS */

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
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

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src.getName()) {
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
  this->_maxEnergyPoints = rhs.getmaxEnergyPoints();
  this->_level = rhs.getLevel();
  this->_meleeAttackDamage = rhs.getmeleeAttackDamage();
  this->_rangedAttackDamage = rhs.getrangedAttackDamage();
  this->_armorDamageReduction = rhs.getarmorDamageReduction();
  return *this;
}