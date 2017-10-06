/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:37:25 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 20:36:13 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {
public:
  Character(std::string const & name);
  Character(Character const & src);
  ~Character(void);

  Character& operator=(Character const & rhs);

  void recoverAP(void);
  void equip(AWeapon* weapon);
  void attack(Enemy* &enemy);
  std::string getName(void) const;
  int getAP(void) const;
  AWeapon *getWeapon(void) const;

private:
  Character(void);

  std::string _name;
  int _AP;
  AWeapon *_weapon;
};

std::ostream & operator<<(std::ostream & stream, Character const & rhs);

#endif