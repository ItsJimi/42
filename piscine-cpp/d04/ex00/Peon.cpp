/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 10:18:12 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 11:30:07 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

/* CONSTRUCTORS */

Peon::Peon(void) {
  std::cout << "Some random Peon called " << this->_name << " just popped !" << std::endl;
  return;
}

Peon::Peon(std::string name) : _name(name) {
  std::cout << "Some random Peon called " << this->_name << " just popped !" << std::endl;
  return;
}

Peon::Peon(Peon const & src) {
  *this = src;
  std::cout << "Some random Peon called " << this->_name << " just popped !" << std::endl;
  return;
}

Peon::~Peon(void) {
  std::cout << "Peon " << this->_name << " just died for no apparent reason !" << std::endl;
  return;
}

/* MEMBERS */

void Peon::getPolymorphed(void) {
  std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
  return;
}

/* OPERATORS */

Peon& Peon::operator=(Peon const & rhs) {
  this->_name = rhs.getName();
  return *this;
}

std::ostream & operator<<(std::ostream & stream, Peon const & rhs) {
  stream << "I am " << rhs.getName() << " and I like otters !";
  return stream;
}