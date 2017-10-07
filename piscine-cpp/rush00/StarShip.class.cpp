/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StarShip.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 10:56:08 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 15:04:58 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StarShip.class.hpp"

/* OPERATORS */

StarShip::StarShip(std::string name, char type, int width, int height, int x, int y) : GameEntity(name, type, width, height, x, y) {
  return;
}

StarShip::StarShip(StarShip const & src) : GameEntity(src) {
  *this = src;
  return;
}

StarShip::~StarShip(void) {
  return;
}

/* MEMBERS */

/* OPERATORS */

StarShip& StarShip::operator=(StarShip const & rhs) {
  this->_x = rhs.getX();
  this->_y = rhs.getY();
  this->_name = rhs.getName();
  this->_moveSize = rhs.getMoveSize();
  this->_type = rhs.getType();
  this->_width = rhs.getWidth();
  this->_height = rhs.getHeight();
  return *this;
}