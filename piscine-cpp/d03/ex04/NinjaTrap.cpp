/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:09:18 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 15:14:06 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

/* CONSTRUCTORS */

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name) {
  this->_hitPoints = 60;
  this->_maxHitPoints = 60;
  this->_energyPoints = 120;
  this->_maxEnergyPoints = 120;
  this->_level = 1;
  this->_meleeAttackDamage = 60;
  this->_rangedAttackDamage = 5;
  this->_armorDamageReduction = 0;

  std::cout << "NINJ4-TP created" << std::endl;

  return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src.getName()) {
  std::cout << "NINJ4-TP created" << std::endl;
  return;
}

NinjaTrap::~NinjaTrap(void) {
  std::cout << "NINJ4-TP deleted" << std::endl;
  return;
}

/* MEMBERS */

void NinjaTrap::rangedAttack(std::string const & target) {
  if (this->_hitPoints == 0) {
    std::cout << "NINJ4-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "NINJ4-TP " << this->_name << " attacks " << target << "at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
  return;
}

void NinjaTrap::meleeAttack(std::string const & target) {
  if (this->_hitPoints == 0) {
    std::cout << "NINJ4-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "NINJ4-TP " << this->_name << " attacks " << target << "at melee, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
  return;
}

void NinjaTrap::ninjaShoebox(ClapTrap & target) {
  if (this->_hitPoints == 0) {
    std::cout << "NINJ4-TP " << this->_name << " can't attack because he haven't hit points." << std::endl;
    return;
  }
  std::cout << "NINJ4-TP " << this->_name << " attacks with his dagger " << target.getName() << ". **It's the standard attack**" << std::endl;
  target.takeDamage(this->_meleeAttackDamage);
  return;
}

void NinjaTrap::ninjaShoebox(NinjaTrap & target) {
  if (this->_hitPoints == 0) {
    std::cout << "NINJ4-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "NINJ4-TP " << this->_name << " attacks with his right foot " << target.getName() << ". **It's a great attack against ninja**" << std::endl;
  target.takeDamage(this->_meleeAttackDamage);
  return;
}

void NinjaTrap::ninjaShoebox(FragTrap & target) {
  if (this->_hitPoints == 0) {
    std::cout << "NINJ4-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "NINJ4-TP " << this->_name << " do a sneaky backside attack to " << target.getName() << ". **Yes... I know, it's bad**" << std::endl;
  target.takeDamage(this->_meleeAttackDamage + 10);
  return;
}

void NinjaTrap::ninjaShoebox(ScavTrap & target) {
  if (this->_hitPoints == 0) {
    std::cout << "NINJ4-TP " << this->_name << " can't attack because he have'nt hit points."<< std::endl;
    return;
  }
  std::cout << "NINJ4-TP " << this->_name << " do a Mega Punch attack to " << target.getName() << ". **It's not very effective...**" << std::endl;
  target.takeDamage(1);
  return;
}

/* OPERATORS */

NinjaTrap& NinjaTrap::operator=(NinjaTrap const & rhs) {
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