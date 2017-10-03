/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:17:16 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 09:27:16 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

Pony::Pony(std::string color) : _color(color) {
  std::cout << "The " << this->_color << " pony has arrived in the forest." << std::endl;
  return;
}

Pony::~Pony(void) {
  std::cout << "The " << this->_color << " pony left the forest." << std::endl;
  return;
}