/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 11:18:00 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 11:29:18 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
  ClapTrap(std::string name);
  ClapTrap(ClapTrap const & src);
  ~ClapTrap(void);

  ClapTrap& operator=(ClapTrap const & rhs);

  void rangedAttack(std::string const & target);
  void meleeAttack(std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string getName(void) const;
  unsigned int getLevel(void) const;
	unsigned int gethitPoints(void) const;
	unsigned int getmaxHitPoints(void) const;
	int getenergyPoints(void) const;
	int getmaxEnergyPoints(void) const;
	int getmeleeAttackDamage(void) const;
	int getrangedAttackDamage(void) const;
	int getarmorDamageReduction(void) const;

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