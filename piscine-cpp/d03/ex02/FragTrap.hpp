/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 08:57:14 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 11:30:10 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap(std::string name);
  FragTrap(FragTrap const & src);
  ~FragTrap(void);

  void vaulthunter_dot_exe(std::string const & target);

  FragTrap& operator=(FragTrap const & rhs);
};

#endif