/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 08:57:14 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 10:36:59 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>

class FragTrap {
public:
  FragTrap(std::string name);
  FragTrap(FragTrap const & src);
  ~FragTrap(void);

  void rangedAttack(std::string const & target);
  void meleeAttack(std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void vaulthunter_dot_exe(std::string const & target);

  std::string getName(void) const;
  unsigned int getLevel(void) const;
	unsigned int gethitPoints(void) const;
	unsigned int getmaxHitPoints(void) const;
	int getenergyPoints(void) const;
	int getmaxEnergyPoints(void) const;
	int getmeleeAttackDamage(void) const;
	int getrangedAttackDamage(void) const;
	int getarmorDamageReduction(void) const;

  FragTrap& operator=(FragTrap const & rhs);

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