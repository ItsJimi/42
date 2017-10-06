/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:00:20 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 14:00:43 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include <iostream>
#include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
  PowerFist(void);
  PowerFist(PowerFist const & src);
  ~PowerFist(void);

  PowerFist& operator=(PowerFist const & rhs);

  virtual void attack(void) const;
};

#endif