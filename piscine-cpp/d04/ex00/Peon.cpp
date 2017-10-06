/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 10:18:12 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 13:22:54 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

/* CONSTRUCTORS */

Peon::Peon(std::string name) : Victim(name) {
  
  std::cout << "Zog zog." << std::endl;
  return;
}

Peon::Peon(Peon const & src) : Victim(src) {
  *this = src;
  std::cout << "Zog zog." << std::endl;
  return;
}

Peon::~Peon(void) {
  std::cout << "Bleuark..." << std::endl;
  return;
}

/* MEMBERS */

void Peon::getPolymorphed(void) const {
  std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
  return;
}

/* OPERATORS */

Peon& Peon::operator=(Peon const & rhs) {
  this->_name = rhs.getName();
  return *this;
}