/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:15:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 14:35:13 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
public:
  HumanB(std::string name);
  ~HumanB(void);
  void attack(void);
  void setWeapon(Weapon& weapon);

private:
  std::string _name;
  Weapon* _weapon;
};

#endif