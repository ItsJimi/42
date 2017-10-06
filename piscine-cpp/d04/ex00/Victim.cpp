/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 10:18:17 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 10:56:14 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

/* CONSTRUCTORS */

Victim::Victim(void) {
  std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
  return;
}

Victim::Victim(std::string name) : _name(name) {
  std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
  return;
}

Victim::Victim(Victim const & src) {
  *this = src;
  std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
  return;
}

Victim::~Victim(void) {
  std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
  return;
}

/* MEMBERS */

std::string Victim::getName(void) {
  return this->_name;
}

void Victim::getPolymorphed(void) {
  std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
  return;
}

/* OPERATORS */

Victim& Victim::operator=(Victim const & rhs) {
  this->_name = rhs.getName();
  return *this;
}

std::ostream & operator<<(std::ostream & stream, Victim const & rhs) {
  stream << "I am " << rhs.getName() << " and I like otters !";
  return stream;
}