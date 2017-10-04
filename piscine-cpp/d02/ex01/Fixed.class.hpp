/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:39:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/04 14:18:21 by jmaiquez         ###   ########.fr       */
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
  Fixed& operator=(Fixed const & rhs);
  int toInt(void) const;
  float toFloat(void) const;

private:
  int _rawBits;
  static int const _bits;
};

std::ostream & operator<<(std::ostream & stream, Fixed const & rhs);

#endif