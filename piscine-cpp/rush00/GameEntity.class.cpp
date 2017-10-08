/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 10:05:16 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/08 20:35:35 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.class.hpp"

/* CONSTRUCTORS */

GameEntity::GameEntity(std::string name, char type, int width, int height, int x, int y) : _name(name), _moveSize(1), _type(type), _width(width), _height(height), _x(x), _y(y) {
  return;
}

GameEntity::GameEntity(GameEntity const & src) {
  *this = src;
  return;
}

GameEntity::~GameEntity(void) {
  return;
}

/* MEMBERS */

void GameEntity::moveTop(void) {
  this->_y -= this->_moveSize;
  return;
}

void GameEntity::moveBottom(void) {
  this->_y += this->_moveSize;
  return;
}

void GameEntity::moveLeft(void) {
  this->_x -= this->_moveSize;
  return;
}

void GameEntity::moveRight(void) {
  this->_x += this->_moveSize;
  return;
}

int GameEntity::getX(void) const {
  return this->_x;
}

int GameEntity::getY(void) const {
  return this->_y;
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

int GameEntity::attack(GameEntity *entity, Point **points) {
  // If player dies, exit
  if (this->getType() == 'o' || entity->getType() == 'o') {
    return -1;
  }

  // Calculate score with size of enemy
  int attackScore = 0;  
  if (this->getType() == 'W' && entity->getType() == '|')
    attackScore = this->getWidth() * this->getHeight();
  else if (this->getType() == '|' && entity->getType() == 'W')
    attackScore = entity->getWidth() * entity->getHeight();

  // Delete entity
  int h = entity->getHeight();
  int w = entity->getWidth();
  int x = entity->getX();
  int y = entity->getY();
  delete entity;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      points[i + y][j + x].entity = NULL;
    }
  }

  // Delete this
  h = this->getHeight();
  w = this->getWidth();
  x = this->getX();
  y = this->getY();
  delete this;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      points[i + y][j + x].entity = NULL;
    }
  }

  // Send score
  return attackScore;
}

/* OPERATORS */

GameEntity& GameEntity::operator=(GameEntity const & rhs) {
  this->_x = rhs.getX();
  this->_y = rhs.getY();
  this->_name = rhs.getName();
  this->_moveSize = rhs.getMoveSize();
  this->_type = rhs.getType();
  this->_width = rhs.getWidth();
  this->_height = rhs.getHeight();
  return *this;
}