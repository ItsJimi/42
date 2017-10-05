/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:06:38 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 15:13:00 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap {
public:
  NinjaTrap(std::string name);
  NinjaTrap(NinjaTrap const & src);
  ~NinjaTrap(void);

  void rangedAttack(std::string const & target);
  void meleeAttack(std::string const & target);
  void ninjaShoebox(ClapTrap & target);
  void ninjaShoebox(NinjaTrap & target);
  void ninjaShoebox(FragTrap & target);
  void ninjaShoebox(ScavTrap & target);

  NinjaTrap& operator=(NinjaTrap const & rhs);
};

#endif