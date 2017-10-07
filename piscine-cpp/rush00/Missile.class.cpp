/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 11:27:34 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 11:27:39 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.class.hpp"

/* OPERATORS */

Missile::Missile(std::string name, char type, int width, int height, Position pos) : GameEntity(name, type, width, height, pos) {
  return;
}

Missile::Missile(Missile const & src) : GameEntity(src) {
  *this = src;
  return;
}

Missile::~Missile(void) {
  return;
}

/* MEMBERS */

/* OPERATORS */

Missile& Missile::operator=(Missile const & rhs) {
  this->_pos = rhs.getPos();
  this->_name = rhs.getName();
  this->_moveSize = rhs.getMoveSize();
  this->_type = rhs.getType();
  this->_width = rhs.getWidth();
  this->_height = rhs.getHeight();
  return *this;
}