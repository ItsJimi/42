/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:10:34 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 17:07:31 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

#include <iostream>
#include <ncurses.h>
#include "GameEntity.class.hpp"
#include "StarShip.class.hpp"
#include "Enemy.class.hpp"
#include "Point.hpp"

class Game {
public:
  Game(int players);
  Game(Game const & src);
  ~Game(void);
  void init(void);
  //void createEnemy(void);
  void display(void);
  void createPlayer(void);
  void fetchAndCalc(void);
  
  Game& operator=(Game const & rhs);

  void setCols(int col);
  int getCols(void);
  void setLines(int lin);
  int getLines(void);
  void moveEntities(void);

private:
  Game(void);

  int _cols;
  int _lines;
  int _players;
  Point **_points;
  int _choice;
};

#endif