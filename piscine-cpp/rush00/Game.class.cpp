/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:16:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 20:43:37 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Logger.hpp"

/* OPERATORS */

Game::Game(int players) : _players(players), _choice(-1) {
  this->_cols = COLS;
  this->_lines = LINES;
  

  /*
  GameEntity *test = new StarShip("Luke", '@', 2, 2, 2, 2);
  this->_points[test->getX()][test->getY()].entity = test;
  this->_points[test->getY() + 1][test->getY()].entity = test;
  this->_points[test->getX() + 1][test->getY() + 1].entity = test;
  this->_points[test->getX()][test->getY() + 1].entity = test;
  */
  return;
}

Game::Game(Game const & src) {
  *this = src;
  return;
}

Game::~Game(void) {
  return;
}

/* MEMBERS */

void  Game::init(void) {
  // std::cout << this->_cols << " : " << this->_lines;  
  this->_points = new Point*[this->_lines];
  for (int i = 0; i < this->_lines; i++) {    
    this->_points[i] = new Point[this->_cols];
  }  


  return;
}

void  Game::createEntity(std::string entity, int x, int y) {
  int w = 1;
  int h = 1;

  GameEntity *tmp;

  if (entity == "StarShip") {
    tmp = new StarShip("Luke", 'o', 1, 1, (int)(this->_cols / 2),  (int)(this->_lines - (h + 1)));
    this->_player = tmp;
  } else if (entity == "Enemy") {
    tmp = new Enemy("Dark Vador", 'W', 1, 1, x,  y);
  } else if (entity == "Missile") {
    tmp = new Missile("Missile", '|', 1, 1, x, y);
  } else {
    return;
  }
  
  int i = 0;
  int j;
  while (i < h){
    j = 0;
    while(j < w){
      this->_points[tmp->getY() + i][tmp->getX() + j].entity = tmp;
      this->_points[i][j].isMoved = false;
      
      j++;
    }
    i++;
  }
  // std::cout << "create"<< i << " " << j << " " << this->_cols << " " << this->_lines << std::endl;
  
  return;
}

void Game::display() {
  int i = 0;
  int j;

  while (i < this->_lines) {
    j = 0;
    while(j < this->_cols) {
      if (this->_points[i][j].entity) {
        mvaddch(i, j, this->_points[i][j].entity->getType());
      } else {
        mvaddch(i, j, ' ');
      }
      j++;
    }
    i++;
  }
  // std::cout << "display"<< i << " " << j << " " << this->_cols << " " << this->_lines << std::endl;

  refresh();
  return;
}

void Game::fetchAndCalc(void) {
  this->_cmp += 1;
  this->_choice = wgetch(stdscr);
  // if (this->_choice != -1) {
  //   // std::cout << this->_choice << " : " << KEY_UP << std::endl;
  //   // Logger logger = Logger("Game.log");
  //   // logger.log("file", std::to_string(this->_choice));
  // }

  if(this->_choice == 32) {
    this->createEntity("Missile", this->_player->getX(), this->_player->getY() - 1);
  }
  return;
}

void  Game::_moveOneEntity(GameEntity *entity, int move) {
  if (move == 1 && entity->getY() == 0 && entity->getType() == 'o') return;
  if (move == 2 && entity->getX() == this->_cols - 1 && entity->getType() == 'o') return;
  if (move == 3 && entity->getY() == this->_lines - 1 && entity->getType() == 'o') return;
  if (move == 4 && entity->getX() == 0 && entity->getType() == 'o') return;
  if (move == 3 && entity->getY() == this->_lines - 1 && entity->getType() != 'o') {
    this->_points[entity->getY()][entity->getX()].entity = NULL;
    delete entity;
    entity = NULL;
    return;
  }
  if (move == 1 && entity->getY() == 0 && entity->getType() != 'o') {
    this->_points[entity->getY()][entity->getX()].entity = NULL;
    delete entity;
    entity = NULL;
    return;
  }

  int i = 0;
  int j;
  while (i < entity->getHeight()) {
    j = 0;
    while(j < entity->getWidth()) {
      this->_points[entity->getY() + i][entity->getX() + j].entity = NULL;
      j++;
    }
    i++;
  }

  switch (move) {
    case 1:
      entity->moveTop();
      break;
    case 2:
      entity->moveRight();
      break;
    case 3:
      entity->moveBottom();
      break;
    case 4:
      entity->moveLeft();
      break;
  }

  // Logger logger = Logger("Game.log");
  // logger.log("file", "move");
  
  // logger.log("file", std::to_string(entity->getX()));
  // logger.log("file", std::to_string(entity->getY()));
  // logger.log("file", std::to_string(entity->getHeight()));
  // logger.log("file", std::to_string(entity->getWidth()));
  
  i = 0;
  while (i < entity->getHeight()) {
    j = 0;
    while(j < entity->getWidth()) {
      // logger.log("file", "in");
      this->_points[entity->getY() + i][entity->getX() + j].entity = entity;
      this->_points[entity->getY() + i][entity->getX() + j].isMoved = true;
      j++;
    }
    i++;
  }
  return;
}

void Game::moveEntities(void) {
  int i = 0;
  int j = 0;
  
  while (i < this->_lines) {
    j = 0;
    while (j < this->_cols) {
      if(this->_points[i][j].isMoved == true){
        j++;
        continue;
      }
      if (this->_points[i][j].entity != NULL) {
        if (this->_points[i][j].entity->getType() == 'W' && this->_cmp % 500 == 0)
          this->_moveOneEntity(this->_points[i][j].entity, 3);
        else if (this->_points[i][j].entity->getType() == '|' && this->_cmp % 100 == 0)
          this->_moveOneEntity(this->_points[i][j].entity, 1);
        else if (this->_points[i][j].entity->getType() == 'o') {
          switch (this->_choice) {
          case 65:
            // std::cout << "test" << std::endl;
            this->_moveOneEntity(this->_points[i][j].entity, 1);
            break;
          case 66:
            this->_moveOneEntity(this->_points[i][j].entity, 3);
            break;
          case 68:
            this->_moveOneEntity(this->_points[i][j].entity, 4);
            break;
          case 67:
            this->_moveOneEntity(this->_points[i][j].entity, 2);
            break;
          }
        }
      }
      j++;
    }
    i++;
  }

  i = 0;
  while (i < this->_lines) {
    j = 0;
    while (j < this->_cols) {
      this->_points[i][j].isMoved = false;
      j++;
    }
    i++;
  }

   this->_choice = -1;
}

/* OPERATORS */

Game &Game::operator=(Game const &rhs) {
  return *this;
}