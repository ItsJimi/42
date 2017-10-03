/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:12:11 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 14:34:25 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
public:
  HumanA(std::string name, Weapon& weapon);
  ~HumanA(void);
  void attack(void);

private:
  std::string _name;
  Weapon& _weapon;
};

#endif