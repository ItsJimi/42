/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:02:30 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/04 18:28:03 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
public:
  Weapon(std::string type);
  ~Weapon(void);
  std::string const & getType(void) const;
  void setType(std::string);

private:
  std::string _type;
};

#endif