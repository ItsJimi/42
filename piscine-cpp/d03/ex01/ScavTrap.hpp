/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:52:38 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 11:08:22 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "FragTrap.hpp"
#include <iostream>

class ScavTrap {
public:
  ScavTrap(std::string name);
  ScavTrap(ScavTrap const & src);
  ~ScavTrap(void);

  void rangedAttack(std::string const & target);
  void meleeAttack(std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void challengeNewcomer(void);

  std::string getName(void) const;
  unsigned int getLevel(void) const;
	unsigned int gethitPoints(void) const;
	unsigned int getmaxHitPoints(void) const;
	int getenergyPoints(void) const;
	int getmaxEnergyPoints(void) const;
	int getmeleeAttackDamage(void) const;
	int getrangedAttackDamage(void) const;
	int getarmorDamageReduction(void) const;

  ScavTrap& operator=(ScavTrap const & rhs);

protected:
  std::string _name;
  
  int _hitPoints;
  int _maxHitPoints;
  int _energyPoints;
  int _maxEnergyPoints;
  int _level;
  int _meleeAttackDamage;
  int _rangedAttackDamage;
  int _armorDamageReduction;
};

#endif