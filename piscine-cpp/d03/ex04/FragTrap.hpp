/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 08:57:14 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 15:12:56 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
  FragTrap(std::string name);
  FragTrap(FragTrap const & src);
  ~FragTrap(void);

  void rangedAttack(std::string const & target);
  void meleeAttack(std::string const & target);
  void vaulthunter_dot_exe(std::string const & target);

  FragTrap& operator=(FragTrap const & rhs);
};

#endif