/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 09:48:46 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 16:11:47 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_CLASS_HPP
# define GAMEENTITY_CLASS_HPP

#include <iostream>

class GameEntity {
public:
  GameEntity(std::string name, char type, int width, int height, int x, int y);
  GameEntity(GameEntity const & src);
  virtual ~GameEntity(void);

  GameEntity& operator=(GameEntity const & rhs);

  void moveTop(void);
  void moveBottom(void);
  void moveLeft(void);
  void moveRight(void);

  int getX(void) const;
  int getY(void) const;
  std::string getName(void) const;
  void setMoveSize(int size);
  int getMoveSize(void) const;
  char getType(void) const;
  int getWidth(void) const;
  int getHeight(void) const;

protected:
  std::string _name;
  int _moveSize;
  char _type;
  int _width;
  int _height;
  int _x;
  int _y;

private:
  GameEntity(void);
};

#endif