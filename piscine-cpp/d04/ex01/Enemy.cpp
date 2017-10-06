/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:09:08 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 14:18:46 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

/* CONSTRUCTORS */

Enemy::Enemy(int hp, std::string const & type) : _hitPoints(hp), _type(type) {
  return;
}

Enemy::Enemy(Enemy const & src) {
  *this = src;
  return;
}

Enemy::~Enemy(void) {
  return;
}

/* MEMBERS */

std::string Enemy::getType(void) const {
  return this->_type;
}
int Enemy::getHP(void) const {
  return this->_hitPoints;
}

void Enemy::takeDamage(int damages) {
  if (damages <= 0) {
    return;
  }
  this->_hitPoints = (this->_hitPoints - damages <= 0) ? 0 : this->_hitPoints - damages;
  return;
}

/* OPERATORS */

Enemy& Enemy::operator=(Enemy const & rhs) {
  this->_hitPoints = rhs.getHP();
  this->_type = rhs.getType();
  return *this;
}