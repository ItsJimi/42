/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:39:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/04 16:55:08 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const & fixed);
  Fixed(int number);
  Fixed(float number);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  int toInt(void) const;
  float toFloat(void) const;

  Fixed& operator=(Fixed const & rhs);

  bool operator==(Fixed const & rhs) const;
  bool operator!=(Fixed const & rhs) const;
  bool operator<(Fixed const & rhs) const;
  bool operator>(Fixed const & rhs) const;
  bool operator<=(Fixed const & rhs) const;
  bool operator>=(Fixed const & rhs) const;

  Fixed operator+(Fixed const & rhs);
  Fixed operator-(Fixed const & rhs);
  Fixed operator*(Fixed const & rhs);
  Fixed operator/(Fixed const & rhs);

  Fixed& operator++(void);
  Fixed operator++(int);
  Fixed& operator--(void);
  Fixed operator--(int);

  static Fixed & max(Fixed & a, Fixed & b);
  static Fixed & min(Fixed & a, Fixed & b);
  static Fixed const & max(Fixed const & a, Fixed const & b);
  static Fixed const & min(Fixed const & a, Fixed const & b);

private:
  int _rawBits;
  static int const _bits;
};

std::ostream & operator<<(std::ostream & stream, Fixed const & rhs);

#endif