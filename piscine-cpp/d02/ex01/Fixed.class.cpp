/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:57:36 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/04 14:12:46 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int const Fixed::_bits = 8;

Fixed::Fixed(void) : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::Fixed(Fixed const & fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
  return;
}

Fixed::Fixed(int number) {
  this->_rawBits = number << this->_bits;
  return;
}

Fixed::Fixed(float number) {
  this->_rawBits = std::roundf(number * this->power(2));
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

std::ostream & operator<<(std::ostream & stream, Fixed const & rhs) {
  stream << rhs.toFloat();
  return stream;
}

int Fixed::power(int nbr) const {
  int result = nbr;
  for (int i = 0; i < this->_bits - 1; i++) {
    result *= nbr;
  }
  return result;
}

int Fixed::toInt(void) const {
  return (this->_rawBits / power(2));
}

float Fixed::toFloat(void) const {
  return (float)this->_rawBits / power(2);
}