/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:46:24 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 17:12:13 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
public:
  T *tab;
  unsigned int length;

  Array(void) {
    std::cout << "Empty" << std::endl;
    this->tab = new T[0]();
    std::cout << "Array created" << std::endl;
    return;
  }

  Array(unsigned int n) {
    std::cout << "Size" << std::endl;
    this->tab = new T[n]();
    this->length = n;
    std::cout << "Array created" << std::endl;
    return;
  }

  Array(Array<T> const & src) {
    std::cout << "Copy" << std::endl;
    *this = src;
    std::cout << "Array created" << std::endl;
    return;
  }

  virtual ~Array(void) {
    delete [] this->tab;
    std::cout << "Array deleted" << std::endl;
    return;
  }

  Array& operator=(Array const & rhs) {
    this->tab = rhs.tab;
    return *this;
  }

  T& operator[](unsigned int n) const {
    if (n >= this->length) {
      throw std::exception();
    }

    return this->tab[n];
  }

  int size(void) const {
    return this->length;
  }
};

#endif