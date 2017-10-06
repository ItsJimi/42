/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 10:18:15 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 10:58:24 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

/* CONSTRUCTORS */

Sorcerer::Sorcerer(void) {
  std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
  return;
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
  std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
  return;
}

Sorcerer::Sorcerer(Sorcerer const & src) {
  *this = src;
  std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
  return;
}

Sorcerer::~Sorcerer(void) {
  std::cout << this->_name << ", " << this->_title << " is dead. Consequences will never be the same !" << std::endl;
  return;
}

/* MEMBERS */

std::string Sorcerer::getName(void) {
  return this->_name;
}

std::string Sorcerer::getTitle(void) {
  return this->_title;
}

void Sorcerer::polymorph(Victim const & victim) const {
  victim.getPolymorphed();
  return;
}

/* OPERATORS */

Sorcerer& Sorcerer::operator=(Sorcerer const & rhs) {
  this->_name = rhs.getName();
  this->_title = rhs.getTitle();
  return *this;
}

std::ostream & operator<<(std::ostream & stream, Sorcerer const & rhs) {
  stream << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !";
  return stream;
}