/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 09:21:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 11:18:31 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "StarShip.class.hpp"
#include "Structs.hpp"

int main(void) {
  Position boatPos;
  boatPos.x = 2;
  boatPos.y = 2;
  StarShip boat = StarShip("Luke", '@', 2, 2, boatPos);
  boat.setMoveSize(2);
  boat.moveRight();
  std::cout << boat.getPos().x << " : " << boat.getPos().y << std::endl;

  return (0);
}