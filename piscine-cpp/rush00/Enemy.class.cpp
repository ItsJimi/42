/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 11:24:56 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/08 18:09:16 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

/* OPERATORS */

Enemy::Enemy(std::string name, char type, int width, int height, int x, int y) : GameEntity(name, type, width, height, x, y) {
  return;
}

Enemy::Enemy(Enemy const & src) : GameEntity(src) {
  *this = src;
  return;
}

Enemy::~Enemy(void) {
  return;
}

/* OPERATORS */

Enemy& Enemy::operator=(Enemy const & rhs) {
  this->_x = rhs.getX();
  this->_y = rhs.getY();
  this->_name = rhs.getName();
  this->_moveSize = rhs.getMoveSize();
  this->_type = rhs.getType();
  this->_width = rhs.getWidth();
  this->_height = rhs.getHeight();
  return *this;
}