/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 11:24:56 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 11:25:38 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

/* OPERATORS */

Enemy::Enemy(std::string name, char type, int width, int height, Position pos) : GameEntity(name, type, width, height, pos) {
  return;
}

Enemy::Enemy(Enemy const & src) : GameEntity(src) {
  *this = src;
  return;
}

Enemy::~Enemy(void) {
  return;
}

/* MEMBERS */

/* OPERATORS */

Enemy& Enemy::operator=(Enemy const & rhs) {
  this->_pos = rhs.getPos();
  this->_name = rhs.getName();
  this->_moveSize = rhs.getMoveSize();
  this->_type = rhs.getType();
  this->_width = rhs.getWidth();
  this->_height = rhs.getHeight();
  return *this;
}