/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:39:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/04 12:51:04 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed & fixed);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  Fixed& operator=(Fixed const & rhs);

private:
  int _rawBits;
  static int const _fractionalBits;
};

#endif