/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 10:52:38 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 11:30:47 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap(std::string name);
  ScavTrap(ScavTrap const & src);
  ~ScavTrap(void);

  void challengeNewcomer(void);

  ScavTrap& operator=(ScavTrap const & rhs);
};

#endif