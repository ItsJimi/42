/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StarShip.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 10:56:08 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 11:04:19 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StarShip.class.hpp"

/* OPERATORS */

StarShip::StarShip(std::string name, char type, int width, int height, Position pos) : GameEntity(name, type, width, height, pos) {
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
  this->_pos = rhs.getPos();
  this->_name = rhs.getName();
  this->_moveSize = rhs.getMoveSize();
  this->_type = rhs.getType();
  this->_width = rhs.getWidth();
  this->_height = rhs.getHeight();
  return *this;
}