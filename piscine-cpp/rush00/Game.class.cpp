/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:16:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 17:09:30 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"

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

void Game::display(){
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


void  Game::createPlayer(void){
  int w = 2;
  int h = 2;

  GameEntity *tmp = new StarShip("Luke", '@', w, h, (int)(this->_cols / 2),  (int)(this->_lines - (h + 1)));

  int i = 0;
  int j;
  while (i < h){
    j = 0;
    while(j < w){
      this->_points[tmp->getY() + i][tmp->getX() + j].entity = tmp;
      j++;
    }
    i++;
  }
  std::cout << "create"<< i << " " << j << " " << this->_cols << " " << this->_lines << std::endl;
  
  return;
}
void Game::fetchAndCalc(void){

  int choice = getch();
  /*
  switch(choice){
    case KEY_UP:
      mvup();
      break;
    case KEY_DOWN:
      mvdown();
      break;
    case KEY_LEFT:
      mvleft();
      break;
    case KEY_RIGHT:
      mvright();
      break;
  }*/
  return;
}

void Game::moveEntities(void) {
  int i = 0;
  int j = 0;


  this->_choice = -1;
}


/* OPERATORS */

Game& Game::operator=(Game const & rhs) {
  return *this;
}