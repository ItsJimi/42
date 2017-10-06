/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:51:51 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 13:57:50 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
public:
  PlasmaRifle(void);
  PlasmaRifle(PlasmaRifle const & src);
  ~PlasmaRifle(void);

  PlasmaRifle& operator=(PlasmaRifle const & rhs);

  virtual void attack(void) const;
};

#endif