/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:10:34 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/08 11:50:42 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

#include <iostream>
#include <ncurses.h>
#include "GameEntity.class.hpp"
#include "StarShip.class.hpp"
#include "Enemy.class.hpp"
#include "Missile.class.hpp"
#include "Point.hpp"

class Game {
public:
  Game(int players);
  Game(Game const & src);
  ~Game(void);
  
  Game& operator=(Game const & rhs);

  void init(void);
  void createEntity(std::string entity, int x, int y, int w, int h);
  void display(void);
  void fetchAndCalc(void);

  void setCols(int col);
  int getCols(void);
  void setLines(int lin);
  int getLines(void);
  void moveEntities(void);
  void popEnemy(void);

private:
  Game(void);

  int _cols;
  int _lines;
  int _players;
  Point **_points;
  int _choice;
  int _cmp;
  GameEntity *_player;

  void _moveOneEntity(GameEntity *entity, int move);
  void _decaleBack(void);
};

#endif