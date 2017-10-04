/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:57:36 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/04 12:48:51 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int const Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::Fixed(Fixed & fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
  return;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
  return;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
  this->_rawBits = raw;
  return;
}

Fixed& Fixed::operator=(Fixed const & rhs) {
  std::cout << "Assignation operator called" << std::endl;
  this->setRawBits(rhs.getRawBits());
  return *this;
}