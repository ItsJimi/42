/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:35:45 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 15:27:41 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon {
public:
  AWeapon(AWeapon const & src);
  AWeapon(std::string const & name, int apcost, int damage);
  virtual ~AWeapon(void);

  AWeapon& operator=(AWeapon const & rhs);

  virtual std::string getName(void) const;
  int getAPCost(void) const;
  int getDamage(void) const;
  virtual void attack(void) const = 0;

private:
  AWeapon(void);

protected:
  std::string _name;
  int _APCost;
  int _damages;

};

#endif