/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 10:05:16 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 11:05:26 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.class.hpp"

/* CONSTRUCTORS */

GameEntity::GameEntity(std::string name, char type, int width, int height, Position pos) : _name(name), _moveSize(1), _type(type), _width(width), _height(height) {
  this->_pos.x = pos.x;
  this->_pos.y = pos.y;

  std::cout << this->_name << " : Game Entity created" << std::endl;
  return;
}

GameEntity::GameEntity(GameEntity const & src) {
  *this = src;
  return;
}

GameEntity::~GameEntity(void) {
  std::cout << this->_name << " : Game Entity deleted" << std::endl;
  return;
}

/* MEMBERS */

void GameEntity::moveTop(void) {
  this->_pos.y -= this->_moveSize;
  return;
}

void GameEntity::moveBottom(void) {
  this->_pos.y += this->_moveSize;
  return;
}

void GameEntity::moveLeft(void) {
  this->_pos.x -= this->_moveSize;
  return;
}
void GameEntity::moveRight(void) {
  this->_pos.x += this->_moveSize;
  return;
}

Position const &GameEntity::getPos(void) const {
  return this->_pos;
}

std::string GameEntity::getName(void) const {
  return this->_name;
}

void GameEntity::setMoveSize(int size) {
  this->_moveSize = size;
  return;
}

int GameEntity::getMoveSize(void) const {
  return this->_moveSize;
}

char GameEntity::getType(void) const {
  return this->_type;
}

int GameEntity::getWidth(void) const {
  return this->_width;
}

int GameEntity::getHeight(void) const {
  return this->_height;
}

/* OPERATORS */

GameEntity& GameEntity::operator=(GameEntity const & rhs) {
  this->_pos = rhs.getPos();
  this->_name = rhs.getName();
  this->_moveSize = rhs.getMoveSize();
  this->_type = rhs.getType();
  this->_width = rhs.getWidth();
  this->_height = rhs.getHeight();
  return *this;
}