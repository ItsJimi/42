/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 10:14:15 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 13:19:06 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim {
public:
  Peon(Peon const & src);
  Peon(std::string name);
  virtual ~Peon(void);

  Peon& operator=(Peon const & rhs);

  virtual void getPolymorphed(void) const;

private:
  Peon(void);
};

#endif