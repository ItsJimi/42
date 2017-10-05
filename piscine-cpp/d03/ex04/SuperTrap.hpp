/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:20:28 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 16:05:14 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
public:
  SuperTrap(std::string name);
  SuperTrap(SuperTrap const & src);
  ~SuperTrap(void);

  using FragTrap::rangedAttack;
  using NinjaTrap::meleeAttack;
  SuperTrap& operator=(SuperTrap const & rhs);
};

#endif