/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:10:34 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/08 17:08:16 by jmaiquez         ###   ########.fr       */
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
  Game(void);
  Game(Game const & src);
  ~Game(void);
  
  Game& operator=(Game const & rhs);

  void init(void);
  void display(void);
  void inputLogic(void);
  void moveEntities(void);

private:
  int _cols;
  int _lines;
  Point **_points;
  int _choice;
  int _cmp;
  GameEntity *_player;
  int _score;

  void _createEntity(std::string entity, int x, int y, int w, int h);
  void _moveOneEntity(GameEntity *entity, int move);
  void _decaleBack(void);
  void _popEnemy(void);
};

#endif